#include "MatchingEngine.h"
#include <iostream>
#include <random>
#include <chrono>

int main() {
    MatchingEngine engine;

    engine.start();

    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> priceDist(100.0, 200.0);
    std::uniform_int_distribution<int> quantityDist(1, 10);
    std::uniform_int_distribution<int> typeDist(0, 1);

    for (int i = 0; i < 20; ++i) {
        OrderType type = static_cast<OrderType>(typeDist(rng));
        double price = priceDist(rng);
        int quantity = quantityDist(rng);
        long long timestamp = std::chrono::system_clock::now().time_since_epoch().count();

        Order order(i, type, price, quantity, timestamp);
        engine.addOrder(order);

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));

    engine.stop();

    return 0;
}