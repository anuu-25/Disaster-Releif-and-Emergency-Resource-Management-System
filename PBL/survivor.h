#ifndef SURVIVOR_H
#define SURVIVOR_H

#include <iostream>
#include <string>
using namespace std;

class Survivor
{
private:
    string id;
    string name;
    int age;
    int severity;
    string junction;

public:
    Survivor();

    Survivor(string id, string name, int age, int severity, string junction);

    void display();

    string getID();
    string getName();
    int getAge();
    int getSeverity();
    string getJunction();

    void setSeverity(int severity);
};

#endif