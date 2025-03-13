#ifndef MATCHINGENGINE_H
#define MATCHINGENGINE_H

#include "OrderBook.h"
#include <thread>
#include <atomic>

class MatchingEngine {
public:
    MatchingEngine();
    ~MatchingEngine();

    void start();

    void stop();

    void addOrder(const Order& order);

private:
    OrderBook orderBook;
    std::atomic<bool> running;
    std::thread matchingThread;

    void run();
};

#endif