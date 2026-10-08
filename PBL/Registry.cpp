#include <iostream>
#include "Registry.h"

using namespace std;

Registry::Registry()
{
    count = 0;
}

void Registry::addSurvivor(Survivor survivor)
{
    for (int i = 0; i < count; i++)
    {
        if (survivors[i].getID() == survivor.getID())
        {
            cout << "Error: Survivor ID already exists!" << endl;
            return;
        }
    }

    if (count < 100)
    {
        survivors[count] = survivor;
        count++;

        cout << "Survivor added successfully!" << endl;
    }
    else
    {
        cout << "Registry is full!" << endl;
    }
}

void Registry::displayAll()
{
    if (count == 0)
    {
        cout << "No survivors registered." << endl;
        return;
    }

    cout << "\n===== ALL REGISTERED SURVIVORS =====" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "\nSurvivor " << i + 1 << ":" << endl;
        survivors[i].display();
    }
}

void Registry::searchByID(string id)
{
    for (int i = 0; i < count; i++)
    {
        if (survivors[i].getID() == id)
        {
            cout << "\nSurvivor Found!" << endl;
            survivors[i].display();
            return;
        }
    }

    cout << "Survivor not found!" << endl;
}