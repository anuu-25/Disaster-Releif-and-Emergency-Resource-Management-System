#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
    count = 0;
}

void PriorityQueue::insert(Survivor s)
{
    if (count == 100)
    {
        cout << "Priority queue is full.\n";
        return;
    }

    int P = count - 1;

    while (P >= 0 && Q[P].getSeverity() < s.getSeverity())
    {
        Q[P + 1] = Q[P];
        P--;
    }

    Q[P + 1] = s;
    count++;
}

void PriorityQueue::clear()
{
    count = 0;
}

void PriorityQueue::display() const
{
    if (count == 0)
    {
        cout << "No victims in the triage queue.\n";
        return;
    }

    cout << "\nEMERGENCY TRIAGE (Highest severity first)\n";

    for (int P = 0; P < count; P++)
    {
        Q[P].display();
    }
}
