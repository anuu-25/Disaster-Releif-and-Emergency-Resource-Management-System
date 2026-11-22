

#include "Convoy.h"

Convoy::Convoy()
{
    head = NULL;
}

Convoy::~Convoy()
{
    Node *P = head;

    while (P != NULL)
    {
        Node *R = P;
        P = P->next;
        delete R;
    }
}

void Convoy::addConvoy(ConvoyData C)
{
    Node *P = new Node;

    P->data = C;
    P->next = head;

    head = P;
}

bool Convoy::isVehicleAvailable(string vehicle) const
{
    Node *P = head;

    while (P != NULL)
    {
        if (P->data.vehicle == vehicle)
        {
            return false;
        }

        P = P->next;
    }

    return true;
}

bool Convoy::removeConvoy(int id)
{
    Node *P = head;
    Node *R = NULL;

    while (P != NULL)
    {
        if (P->data.ID == id)
        {
            if (R == NULL)
            {
                head = P->next;
            }
            else
            {
                R->next = P->next;
            }

            delete P;

            return true;
        }

        R = P;
        P = P->next;
    }

    return false;
}

bool Convoy::returnVehicle(int id)
{
    if (removeConvoy(id))
    {
        cout << "Vehicle returned successfully!" << endl;
        return true;
    }

    cout << "Convoy ID not found." << endl;

    return false;
}

void Convoy::displayConvoys() const
{
    Node *P = head;

    if (P == NULL)
    {
        cout << "No active convoys." << endl;
        return;
    }

    cout << "\nACTIVE RESCUE CONVOYS\n";

    while (P != NULL)
    {
        cout << "Convoy ID: " << P->data.ID << endl;

        cout << "Vehicle: "
             << P->data.vehicle << endl;

        cout << "Destination: "
             << P->data.destination << endl;

        cout << "Status: Dispatched" << endl;

        cout << "-----------------------" << endl;

        P = P->next;
    }
}

int Convoy::copyConvoys(ConvoyData list[], int limit) const
{
    Node *P = head;
    int count = 0;

    while (P != NULL && count < limit)
    {
        list[count] = P->data;
        count++;

        P = P->next;
    }

    return count;
}
