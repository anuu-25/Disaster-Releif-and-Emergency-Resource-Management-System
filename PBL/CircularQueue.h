#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include "SupplyBatch.h"

class CircularQueue
{
private:
    SupplyBatch queue[100];
    int front;
    int rear;
    int count;

public:
    CircularQueue();

    bool isFull();
    bool isEmpty();
    bool enqueue(SupplyBatch batch);
    bool dequeue();
    SupplyBatch getFront();
    void display();
    bool findBatch(string batchID, SupplyBatch &result);
};

#endif