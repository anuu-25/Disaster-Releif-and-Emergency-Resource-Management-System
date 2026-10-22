#include <iostream>
#include "CircularQueue.h"

using namespace std;

CircularQueue::CircularQueue()
{
    front = -1;
    rear = -1;
    count = 0;
}

bool CircularQueue::isFull()
{
    return count == 100;
}

bool CircularQueue::isEmpty()
{
    return count == 0;
}

bool CircularQueue::enqueue(SupplyBatch batch)
{
    if (isFull())
    {
        cout << "Queue Overflow: Circular queue is full!" << endl;
        return false;
    }

    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % 100;
    }

    queue[rear] = batch;
    count++;
    cout << "Supply batch loaded into truck queue successfully!" << endl;
    return true;
}

bool CircularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Underflow: No supply batch to dispatch!" << endl;
        return false;
    }

    cout << "\nDispatching Supply Batch:" << endl;
    queue[front].display();

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % 100;
    }

    count--;
    return true;
}

SupplyBatch CircularQueue::getFront()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return SupplyBatch();
    }
    return queue[front];
}

void CircularQueue::display()
{
    if (isEmpty())
    {
        cout << "Circular Queue is empty!" << endl;
        return;
    }

    cout << "\n===== CIRCULAR TRUCK LOADING QUEUE =====" << endl;
    int index = front;
    for (int i = 0; i < count; i++)
    {
        cout << "\nSlot " << i + 1 << ":" << endl;
        queue[index].display();
        index = (index + 1) % 100;
    }
}

bool CircularQueue::findBatch(string batchID, SupplyBatch &result)
{
    if (isEmpty())
        return false;

    int index = front;

    for (int i = 0; i < count; i++)
    {
        if (queue[index].getBatchID() == batchID)
        {
            result = queue[index];
            return true;
        }

        index = (index + 1) % 100;
    }

    return false;
}
