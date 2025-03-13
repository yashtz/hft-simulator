#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include <set>
#include <vector>
#include <mutex>

class OrderBook {
public:
    void addOrder(const Order& order);

    void matchOrders();

    void display() const;

private:
    std::set<Order> buyOrders;
    std::set<Order> sellOrders;

    mutable std::mutex mtx;
};

#endif