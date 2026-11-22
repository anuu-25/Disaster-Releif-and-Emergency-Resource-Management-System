
#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct SupplyBatch
{
    int ID;
    string item;
    int quantity;
    string camp;
};

class CircularQueue
{
private:
    SupplyBatch Q[10];
    int front;
    int rear;
    int count;

public:
    CircularQueue();

    bool isFull() const;
    bool isEmpty() const;

    void insert(SupplyBatch S);
    bool dispatchSelected(int choice);

    int getCount() const;

    void display() const;
};

#endif
