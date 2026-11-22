#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Survivor.h"

class PriorityQueue
{
private:
    Survivor Q[100];
    int count;

public:
    PriorityQueue();
    void insert(Survivor s);
    void clear();
    void display() const;
};

#endif
