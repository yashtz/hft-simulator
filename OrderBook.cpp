#include "OrderBook.h"
#include <iostream>

bool operator<(const Order& a, const Order& b) {
    if (a.price == b.price) {
        return a.timestamp < b.timestamp;
    }
    return (a.type == OrderType::BUY) ? (a.price > b.price) : (a.price < b.price);
}

void OrderBook::addOrder(const Order& order) {
    std::lock_guard<std::mutex> lock(mtx);

    if (order.type == OrderType::BUY) {
        buyOrders.insert(order);
    } else {
        sellOrders.insert(order);
    }
}

void OrderBook::matchOrders() {
    std::lock_guard<std::mutex> lock(mtx);

    while (!buyOrders.empty() && !sellOrders.empty()) {
        auto highestBid = buyOrders.begin();
        auto lowestAsk = sellOrders.begin();

        if (highestBid->price >= lowestAsk->price) {
            int tradeQuantity = std::min(highestBid->quantity, lowestAsk->quantity);
            std::cout << "Trade executed: " << tradeQuantity
                      << " units @ " << lowestAsk->price << "\n";

            if (highestBid->quantity > tradeQuantity) {
                Order updatedBuyOrder = *highestBid;
                updatedBuyOrder.quantity -= tradeQuantity;
                buyOrders.erase(highestBid);
                buyOrders.insert(updatedBuyOrder);
            } else {
                buyOrders.erase(highestBid);
            }

            if (lowestAsk->quantity > tradeQuantity) {
                Order updatedSellOrder = *lowestAsk;
                updatedSellOrder.quantity -= tradeQuantity;
                sellOrders.erase(lowestAsk);
                sellOrders.insert(updatedSellOrder);
            } else {
                sellOrders.erase(lowestAsk);
            }
        } else {
            break;
        }
    }
}

void OrderBook::display() const {
    std::lock_guard<std::mutex> lock(mtx);

    std::cout << "\nBUY ORDERS:\n";
    for (const auto& order : buyOrders) {
        order.display();
    }

    std::cout << "\nSELL ORDERS:\n";
    for (const auto& order : sellOrders) {
        order.display();
    }
}