#include <iostream>
#include "PriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue()
{
    count = 0;
}

void PriorityQueue::insert(Survivor survivor)
{
    if (count == 100)
    {
        cout << "Priority Queue is full!" << endl;
        return;
    }

    int i = count;

    while (i > 0 &&
           queue[i - 1].getSeverity() < survivor.getSeverity())
    {
        queue[i] = queue[i - 1];
        i--;
    }

    queue[i] = survivor;
    count++;

    cout << "Survivor added to Priority Queue!" << endl;
}

void PriorityQueue::removeHighest()
{
    if (count == 0)
    {
        cout << "Priority Queue is empty!" << endl;
        return;
    }

    cout << "\nHighest Priority Survivor:" << endl;
    queue[0].display();

    for (int i = 1; i < count; i++)
    {
        queue[i - 1] = queue[i];
    }

    count--;
}

void PriorityQueue::display()
{
    if (count == 0)
    {
        cout << "Priority Queue is empty!" << endl;
        return;
    }

    cout << "\n===== PRIORITY QUEUE =====" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "\nPriority " << i + 1 << ":" << endl;
        queue[i].display();
    }
}