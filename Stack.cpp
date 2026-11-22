#include "Stack.h"

Stack::Stack()
{
    top = -1;
}

bool Stack::isEmpty() const
{
    return top == -1;
}

bool Stack::isFull() const
{
    return top == 19;
}

void Stack::push(ConvoyData C)
{
    if (isFull())
    {
        cout << "Undo stack is full.\n";
        return;
    }

    top++;
    S[top] = C;
}

bool Stack::pop(ConvoyData &C)
{
    if (isEmpty())
    {
        return false;
    }

    C = S[top];
    top--;
    return true;
}
