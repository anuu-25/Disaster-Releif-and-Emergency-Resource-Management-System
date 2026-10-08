#include <iostream>
#include <string>
#include "survivor.h"
#include "Registry.h"
#include "PriorityQueue.h"

using namespace std;

int main()
{
    Registry registry;
    PriorityQueue priorityQueue;

    string id, name, junction;
    int age, severity, ch;

    do
    {
        cout << "\n===== DISASTER RELIEF SYSTEM =====" << endl;
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Display Priority Queue";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter Survivor ID: ";
            cin >> id;

            cout << "Enter Survivor Name: ";
            cin >> name;

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter Severity (1-5): ";
            cin >> severity;

            cout << "Enter Trapped Junction: ";
            cin >> junction;

            {
                Survivor s1(id, name, age, severity, junction);
                if (registry.addSurvivor(s1))
                {
                    priorityQueue.insert(s1);
                }
            }

            break;

        case 2:
            registry.displayAll();
            break;

        case 3:
            priorityQueue.display();
            break;    

        case 4:
            cout << "\nExiting program..." << endl;
            break;

        default:
            cout << "\nInvalid choice!" << endl;
        }

    } while (ch != 4);

    return 0;
}