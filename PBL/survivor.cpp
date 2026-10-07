#include "Survivor.h"

Survivor::Survivor()
{
    id = "";
    name = "";
    age = 0;
    severity = 0;
    junction = "";
}

Survivor::Survivor(string id, string name, int age, int severity, string junction)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->severity = severity;
    this->junction = junction;
}

void Survivor::display()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Severity: " << severity << endl;
    cout << "Junction: " << junction << endl;
}

string Survivor::getID()
{
    return id;
}

string Survivor::getName()
{
    return name;
}

int Survivor::getAge()
{
    return age;
}

int Survivor::getSeverity()
{
    return severity;
}

string Survivor::getJunction()
{
    return junction;
}

void Survivor::setSeverity(int severity)
{
    this->severity = severity;
}