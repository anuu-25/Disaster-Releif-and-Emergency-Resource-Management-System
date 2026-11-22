
#include "CircularQueue.h"

CircularQueue::CircularQueue()
{
    front = 0;
    rear = -1;
    count = 0;
}

bool CircularQueue::isFull() const
{
    return count == 10;
}

bool CircularQueue::isEmpty() const
{
    return count == 0;
}

int CircularQueue::getCount() const
{
    return count;
}

void CircularQueue::insert(SupplyBatch S)
{
    if (isFull())
    {
        cout << "Supply queue is full.\n";
        return;
    }

    rear = (rear + 1) % 10;

    Q[rear] = S;

    count++;

    cout << "Supply batch added to queue.\n";
}

void CircularQueue::display() const
{
    if (isEmpty())
    {
        cout << "Supply queue is empty.\n";
        return;
    }

    cout << "\nPENDING SUPPLY BATCHES\n";

    for (int P = 0; P < count; P++)
    {
        int R = (front + P) % 10;

        cout << P + 1 << ". "
             << Q[R].item
             << " | Quantity: " << Q[R].quantity
             << " | Camp: " << Q[R].camp
             << " | Batch ID: " << Q[R].ID
             << endl;
    }
}

bool CircularQueue::dispatchSelected(int choice)
{
    if (isEmpty())
    {
        cout << "No supply batch is waiting.\n";
        return false;
    }

    if (choice < 1 || choice > count)
    {
        cout << "Invalid supply choice.\n";
        return false;
    }

    SupplyBatch temp[10];

    int selectedIndex = choice - 1;
    SupplyBatch selected = Q[(front + selectedIndex) % 10];

    int newCount = 0;

    for (int P = 0; P < count; P++)
    {
        if (P != selectedIndex)
        {
            int R = (front + P) % 10;

            temp[newCount] = Q[R];
            newCount++;
        }
    }

    for (int P = 0; P < newCount; P++)
    {
        Q[P] = temp[P];
    }

    front = 0;
    count = newCount;
    rear = count - 1;

    cout << "\nSUPPLY DISPATCHED SUCCESSFULLY\n";
    cout << "Batch ID: " << selected.ID << endl;
    cout << "Item: " << selected.item << endl;
    cout << "Quantity: " << selected.quantity << endl;
    cout << "Destination: " << selected.camp << endl;

    return true;
}
