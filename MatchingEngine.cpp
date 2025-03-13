#include "MatchingEngine.h"
#include <iostream>
#include <chrono>
#include <thread>

MatchingEngine::MatchingEngine()
    : running(false) {}

MatchingEngine::~MatchingEngine() {
    stop();
}

void MatchingEngine::start() {
    running = true;
    matchingThread = std::thread(&MatchingEngine::run, this);
}

void MatchingEngine::stop() {
    running = false;
    if (matchingThread.joinable()) {
        matchingThread.join();
    }
}

void MatchingEngine::addOrder(const Order& order) {
    orderBook.addOrder(order);
}

void MatchingEngine::run() {
    while (running) {
        orderBook.matchOrders();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}