#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "survivor.h"

class PriorityQueue
{
private:
    Survivor queue[100];
    int count;

public:
    PriorityQueue();

    void insert(Survivor survivor);
    void removeHighest();
    void display();
};

#endif