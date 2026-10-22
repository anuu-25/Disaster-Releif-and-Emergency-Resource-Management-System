
#include <iostream>
#include "Convoy.h"

using namespace std;

Convoy::Convoy()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
    nextTruckNumber = 101;
}

Convoy::~Convoy()
{
    ConvoyNode *current = head;

    while (current != nullptr)
    {
        ConvoyNode *next = current->next;
        delete current;
        current = next;
    }
}

void Convoy::addTruck(SupplyBatch batch)
{
    ConvoyNode *newNode = new ConvoyNode();

    newNode->truckID = "T" + to_string(nextTruckNumber);
    nextTruckNumber++;

    newNode->batch = batch;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    count++;

    cout << "\nTruck assigned successfully!" << endl;
    cout << "Truck ID: " << newNode->truckID << endl;
    newNode->batch.display();
}

bool Convoy::removeTruck(string truckID)
{
    if (head == nullptr)
    {
        cout << "Convoy is empty!" << endl;
        return false;
    }

    ConvoyNode *current = head;

    while (current != nullptr)
    {
        if (current->truckID == truckID)
        {
            if (current->prev != nullptr)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next != nullptr)
                current->next->prev = current->prev;
            else
                tail = current->prev;

            delete current;
            count--;

            cout << "Truck " << truckID
                 << " removed from convoy!" << endl;
            return true;
        }

        current = current->next;
    }

    cout << "Truck not found!" << endl;
    return false;
}

void Convoy::displayForward()
{
    if (head == nullptr)
    {
        cout << "Convoy list is empty!" << endl;
        return;
    }

    cout << "\n===== CONVOY DETAILS =====" << endl;

    ConvoyNode *current = head;

    while (current != nullptr)
    {
        cout << "\nTruck ID: " << current->truckID << endl;
        current->batch.display();
        current = current->next;
    }
}

void Convoy::displayBackward()
{
    if (tail == nullptr)
    {
        cout << "Convoy list is empty!" << endl;
        return;
    }

    cout << "\n===== CONVOY DETAILS (BACKWARD) =====" << endl;

    ConvoyNode *current = tail;

    while (current != nullptr)
    {
        cout << "\nTruck ID: " << current->truckID << endl;
        current->batch.display();
        current = current->prev;
    }
}
