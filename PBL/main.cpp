#include <iostream>
#include <string>
#include "Survivor.h"
#include "Registry.h"

using namespace std;

int main()
{
    Registry registry;

    string id, name, junction;
    int age, severity, ch;

    do
    {
        cout << "\n===== DISASTER RELIEF SYSTEM =====" << endl;
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Exit";
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
                registry.addSurvivor(s1);
            }

            break;

        case 2:
            registry.displayAll();
            break;

        case 3:
            cout << "\nExiting program..." << endl;
            break;

        default:
            cout << "\nInvalid choice!" << endl;
        }

    } while (ch != 3);

    return 0;
}
