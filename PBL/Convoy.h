
#ifndef CONVOY_H
#define CONVOY_H

#include <iostream>
#include <string>
using namespace std;

struct ConvoyData
{
    int ID;
    string vehicle;
    string destination;
};

class Convoy
{
private:
    struct Node
    {
        ConvoyData data;
        Node *next;
    };

    Node *head;

public:
    Convoy();
    ~Convoy();
    void addConvoy(ConvoyData C);
    void displayConvoys() const;
    int copyConvoys(ConvoyData list[], int limit) const;
    bool removeConvoy(int id);
    bool isVehicleAvailable(string vehicle) const;
    bool returnVehicle(int id);
};

#endif
