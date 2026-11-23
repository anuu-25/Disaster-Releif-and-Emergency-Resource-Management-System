#include "Survivor.h"

Survivor::Survivor()
{
    ID = 0;
    age = 0;
    severity = 1;
    name = "Unknown";
    junction = "J1";
    condition = "Not specified";
}

Survivor::Survivor(int id, string n, int a, int s, string j, string c)
{
    ID = id;
    name = n;
    age = a;
    severity = s;
    junction = j;
    condition = c;
}

int Survivor::getID() const
{
    return ID;
}

int Survivor::getSeverity() const
{
    return severity;
}

string Survivor::getName() const
{
    return name;
}

int Survivor::getAge() const
{
    return age;
}

string Survivor::getJunction() const
{
    return junction;
}

string Survivor::getCondition() const
{
    return condition;
}

void Survivor::setSeverity(int s)
{
    severity = s;
}

void Survivor::display() const
{
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Severity: " << severity << endl;
    cout << "Junction: " << junction << endl;
    cout << "Condition: " << condition << endl;
    cout << "-----------------------------" << endl;
}
