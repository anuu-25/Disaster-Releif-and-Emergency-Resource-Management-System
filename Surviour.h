#ifndef SURVIVOR_H
#define SURVIVOR_H

#include <iostream>
#include <string>
using namespace std;

class Survivor
{
private:
    int ID;
    string name;
    int age;
    int severity;
    string junction;
    string condition;

public:
    Survivor();
    Survivor(int id, string n, int a, int s, string j, string c);

    int getID() const;
    int getSeverity() const;
    string getName() const;
    int getAge() const;
    string getJunction() const;
    string getCondition() const;
    void setSeverity(int s);
    void display() const;
};

#endif
