#include "Order.h"
#include <iostream>

Order::Order(int id, OrderType type, double price, int quantity, long long timestamp)
    : id(id), type(type), price(price), quantity(quantity), timestamp(timestamp) {}

void Order::display() const {
    std::string typeStr = (type == OrderType::BUY) ? "BUY" : "SELL";
    std::cout << "Order ID: " << id
              << " | Type: " << typeStr
              << " | Price: " << price
              << " | Quantity: " << quantity
              << " | Timestamp: " << timestamp << "\n";
}