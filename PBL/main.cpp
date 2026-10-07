#include <iostream>
#include <string>
#include "Survivor.h"

using namespace std;

int main()
{
    string id;
    string name;
    int age;
    int severity;
    string junction;

    cout << "===== DISASTER RELIEF SYSTEM =====" << endl;

    cout << "Enter Survivor ID: ";
    cin >> id;

    cout << "Enter Survivor Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Severity (1-5): ";
    cin >> severity;

    cout << "Enter Trapped Junction: ";
    cin >> junction;

    Survivor s1(id, name, age, severity, junction);

    cout << "\n===== SURVIVOR DETAILS =====" << endl;

    s1.display();

    return 0;
}