#ifndef STACK_H
#define STACK_H

#include "Convoy.h"

class Stack
{
private:
    ConvoyData S[20];
    int top;

public:
    Stack();
    bool isEmpty() const;
    bool isFull() const;
    void push(ConvoyData C);
    bool pop(ConvoyData &C);
};

#endif
