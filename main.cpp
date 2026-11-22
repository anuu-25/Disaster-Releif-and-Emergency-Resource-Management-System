
#include <iostream>
#include <limits>
#include "Survivor.h"
#include "Registry.h"
#include "PriorityQueue.h"
#include "CircularQueue.h"
#include "Convoy.h"
#include "Stack.h"
#include "RoadNetwork.h"

using namespace std;

int readNumber(string message, int low, int high)
{
    int number;

    while (true)
    {
        cout << message;
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number.\n";
        }
        else if (number < low || number > high)
        {
            cout << "Enter a value between "
                 << low << " and " << high << ".\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
    }
}

string readText(string message)
{
    string value;

    cout << message;
    getline(cin, value);

    return value;
}


void showMenu()
{
    cout << "\n";
    cout << "====================================================\n";
    cout << "                    CRISISGRID                      \n";
    cout << "       DISASTER RELIEF AND EMERGENCY SYSTEM          \n";
    cout << "====================================================\n";

    cout << "\n--------------- SURVIVOR MANAGEMENT ----------------\n";
    cout << "  1. View All Survivors\n";
    cout << "  2. Register New Survivor\n";
    cout << "  3. Search Survivor\n";
    cout << "  4. Update Survivor Severity\n";

    cout << "\n---------- EMERGENCY AND SUPPLY MANAGEMENT ----------\n";
    cout << "  5. View Emergency Triage Queue\n";
    cout << "  6. View Pending Supplies\n";
    cout << "  7. Add Supply Batch\n";
    cout << "  8. Dispatch Supply Batch\n";

    cout << "\n------------- RESCUE CONVOY MANAGEMENT --------------\n";
    cout << "  9. Dispatch Rescue Vehicle\n";
    cout << " 10. View Active Convoys\n";
    cout << " 11. Undo Convoy Dispatch\n";

    cout << "\n------------------- ROAD NETWORK --------------------\n";
    cout << " 12. View Road Network\n";
    cout << " 13. Find Shortest Safe Route\n";

    cout << "\n------------------ DATA MANAGEMENT ------------------\n";
    cout << " 14. Save Survivor Records\n";

    cout << "\n====================================================\n";
    cout << "  0. Exit System\n";
    cout << "====================================================\n";
}


int main()
{
    Registry registry;
    PriorityQueue triage;
    CircularQueue supplies;
    Convoy convoys;
    Stack undoStack;
    RoadNetwork roads;

    registry.loadFromFile();

    if (registry.isEmpty())
    {
        registry.addSurvivor(
            Survivor(1001, "Aarav", 32, 5, "J1", "Severe injury")
        );

        registry.addSurvivor(
            Survivor(1002, "Meera", 24, 3, "J3", "Fracture")
        );

        registry.addSurvivor(
            Survivor(1003, "Rohan", 45, 2, "J2", "Minor injury")
        );
    }

    // Sample supplies are added automatically.
    SupplyBatch B1 = {501, "Water", 50, "J1"};
    SupplyBatch B2 = {502, "Medicine", 20, "J3"};
    SupplyBatch B3 = {503, "Food Packets", 40, "J4"};

    supplies.insert(B1);
    supplies.insert(B2);
    supplies.insert(B3);

    Survivor savedList[100];

    int savedCount = registry.copySurvivors(savedList, 100);

    for (int P = 0; P < savedCount; P++)
    {
        triage.insert(savedList[P]);
    }

    int nextID = registry.getLastID() + 1;
    int nextBatchID = 504;
    int nextConvoyID = 701;
    int choice;

    do
    {
        showMenu();

        choice = readNumber("Enter your choice: ", 0, 14);

        if (choice == 1)
        {
            registry.displayAll();
        }

        else if (choice == 2)
        {
            string name = readText("Enter survivor name: ");
            int age = readNumber("Enter age: ", 1, 120);
            int severity = readNumber("Enter severity (1-5): ", 1, 5);
            int junction = readNumber("Enter junction (1-5): ", 1, 5);

            string condition = readText("Enter medical condition: ");

            string place = "J" + to_string(junction);

            Survivor S(nextID, name, age, severity, place, condition);

            registry.addSurvivor(S);
            triage.insert(S);

            cout << "Survivor registered. Generated ID: "
                 << nextID << endl;

            nextID++;
        }

        else if (choice == 3)
        {
            string name;

            cout << "\nSEARCH SURVIVOR" << endl;
            cout << "Enter survivor name: ";

            getline(cin, name);

            registry.searchByName(name);
        }

        else if (choice == 4)
        {
            int id = readNumber("Enter survivor ID: ", 1, 999999);
            int severity = readNumber("Enter new severity (1-5): ", 1, 5);

            if (registry.updateSeverity(id, severity))
            {
                triage.clear();

                int total = registry.copySurvivors(savedList, 100);

                for (int P = 0; P < total; P++)
                {
                    triage.insert(savedList[P]);
                }
            }
        }

        else if (choice == 5)
        {
            cout << "Severity 5 is the highest emergency priority.\n";
            triage.display();
        }

        else if (choice == 6)
        {
            supplies.display();
        }

        else if (choice == 7)
        {
            cout << "Available camps: J1, J2, J3, J4, J5\n";

            string item = readText("Enter supply name: ");
            int quantity = readNumber("Enter quantity: ", 1, 10000);
            int camp = readNumber("Enter destination camp (1-5): ", 1, 5);

            SupplyBatch B;

            B.ID = nextBatchID;
            B.item = item;
            B.quantity = quantity;
            B.camp = "J" + to_string(camp);

            supplies.insert(B);

            nextBatchID++;
        }

        
else if (choice == 8)
{
    if (supplies.isEmpty())
    {
        cout << "No supply batches are pending." << endl;
    }
    else
    {
        supplies.display();

        int selected = readNumber(
            "\nWhich supply do you want to dispatch? ",
            1,
            supplies.getCount()
        );

        supplies.dispatchSelected(selected);
    }
}


        else if (choice == 9)
        {
            cout << "\nAVAILABLE VEHICLES\n";

            cout << "1. Ambulance";

            if (!convoys.isVehicleAvailable("Ambulance"))
            {
                cout << " (Not Available)";
            }

            cout << endl;

            cout << "2. Rescue Van";

            if (!convoys.isVehicleAvailable("Rescue Van"))
            {
                cout << " (Not Available)";
            }

            cout << endl;

            cout << "3. Supply Truck";

            if (!convoys.isVehicleAvailable("Supply Truck"))
            {
                cout << " (Not Available)";
            }

            cout << endl;

            int vehicleChoice = readNumber(
                "Select vehicle (1-3): ", 1, 3
            );

            string vehicle;

            if (vehicleChoice == 1)
            {
                vehicle = "Ambulance";
            }
            else if (vehicleChoice == 2)
            {
                vehicle = "Rescue Van";
            }
            else
            {
                vehicle = "Supply Truck";
            }

            if (!convoys.isVehicleAvailable(vehicle))
            {
                cout << "This vehicle is already dispatched." << endl;
            }
            else
            {
                int camp = readNumber(
                    "Enter destination junction (1-5): ", 1, 5
                );

                ConvoyData C;

                C.ID = nextConvoyID;
                C.vehicle = vehicle;
                C.destination = "J" + to_string(camp);

                convoys.addConvoy(C);
                undoStack.push(C);

                cout << "Convoy dispatched successfully!" << endl;
                cout << "Convoy ID: " << nextConvoyID << endl;

                nextConvoyID++;
            }
        }

        else if (choice == 10)
        {
            convoys.displayConvoys();
        }

        else if (choice == 11)
        {
            ConvoyData active[20];

            int count = convoys.copyConvoys(active, 20);

            if (count == 0)
            {
                cout << "There are no active convoys to undo." << endl;
            }
            else
            {
                cout << "\nSELECT VEHICLE TO UNDO\n";

                for (int P = 0; P < count; P++)
                {
                    cout << P + 1 << ". "
                         << active[P].vehicle << endl;
                }

                int selected = readNumber(
                    "Which vehicle do you want to undo? ",
                    1,
                    count
                );

                int id = active[selected - 1].ID;

                convoys.removeConvoy(id);
                undoStack.removeByID(id);

                cout << active[selected - 1].vehicle
                     << " dispatch has been undone successfully!"
                     << endl;
            }
        }

        else if (choice == 12)
        {
            roads.displayRoads();
        }

        else if (choice == 13)
        {
            int start = readNumber(
                "Enter starting junction (1-5): ", 1, 5
            );

            int end = readNumber(
                "Enter destination junction (1-5): ", 1, 5
            );

            roads.findSafeRoute(start, end);
        }

        else if (choice == 14)
        {
            registry.saveToFile();
        }

        else if (choice == 0)
        {
            registry.saveToFile();

            cout << "Thank you for using CrisisGrid.\n";
        }

    } while (choice != 0);

    return 0;
}
