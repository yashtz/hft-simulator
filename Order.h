#ifndef ORDER_H
#define ORDER_H

#include <string>

enum class OrderType { BUY, SELL };

class Order {
public:
    int id;               
    OrderType type;       
    double price;         
    int quantity;         
    long long timestamp; 

    Order(int id, OrderType type, double price, int quantity, long long timestamp);
    void display() const;
};

#endif