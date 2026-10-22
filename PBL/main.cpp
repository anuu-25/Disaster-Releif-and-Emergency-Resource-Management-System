
#include <iostream>
#include <string>
#include "survivor.h"
#include "Registry.h"
#include "PriorityQueue.h"
#include "SupplyBatch.h"
#include "CircularQueue.h"
#include "Convoy.h"

using namespace std;

int main()
{
    Registry registry;
    PriorityQueue priorityQueue;
    CircularQueue truckQueue;
    Convoy convoy;

    string id, name, junction;
    string batchID, itemType, destination;
    string truckID, driverName;

    int age, severity, quantity, ch;

    do
    {
        cout << "\n===== DISASTER RELIEF SYSTEM =====" << endl;

        cout << "\n--- Victim Management ---" << endl;
        cout << "1. Insert Survivor" << endl;
        cout << "2. Display All Survivors" << endl;
        cout << "3. Display Priority Queue" << endl;

        cout << "\n--- Supply and Convoy Management ---" << endl;
        cout << "4. Load Supply Batch" << endl;
        cout << "5. Dispatch Supply Batch" << endl;
        cout << "6. Display Supply Queue" << endl;
        cout << "7. Add Truck to Convoy" << endl;
        cout << "8. Remove Truck from Convoy" << endl;
        cout << "9. Display Convoy" << endl;
        //cout << "10. Merge Two Supply Batches" << endl;
        cout << "10. Exit" << endl;

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
            cout << "\nEnter Batch ID: ";
            cin >> batchID;

            cout << "Enter Item Type: ";
            cin >> itemType;

            cout << "Enter Quantity: ";
            cin >> quantity;

            cout << "Enter Destination Junction: ";
            cin >> destination;

            {
                SupplyBatch batch(batchID, itemType, quantity, destination);
                truckQueue.enqueue(batch);
            }
            break;

        case 5:
            truckQueue.dequeue();
            break;

        case 6:
            truckQueue.display();
            break;

        
        case 7:
        {
            string searchID;
            SupplyBatch batch;

            cout << "\nEnter Batch ID to assign to truck: ";
            cin >> searchID;

            if (truckQueue.findBatch(searchID, batch))
            {
                convoy.addTruck(batch);
            }
            else
            {
                cout << "Batch ID not found! Please load the supply first."
             << endl;
            }

          break;
        }


        case 8:
            cout << "\nEnter Truck ID to remove: ";
            cin >> truckID;

            convoy.removeTruck(truckID);
            break;

        case 9:
        {
            int choice;

            cout << "\n1. Display Forward" << endl;
            cout << "2. Display Backward" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 1)
                convoy.displayForward();
            else if (choice == 2)
                convoy.displayBackward();
            else
                cout << "Invalid choice!" << endl;

            break;
        }

    

        case 10:
            cout << "\nExiting program..." << endl;
            break;

        default:
            cout << "\nInvalid choice!" << endl;
        }

    } while (ch != 11);

    return 0;
}
