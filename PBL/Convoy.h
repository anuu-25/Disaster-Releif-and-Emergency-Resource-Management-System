
#ifndef CONVOY_H
#define CONVOY_H

#include <iostream>
#include <string>
#include "SupplyBatch.h"

using namespace std;

struct ConvoyNode
{
    string truckID;
    SupplyBatch batch;
    ConvoyNode *next;
    ConvoyNode *prev;
};

class Convoy
{
private:
    ConvoyNode *head;
    ConvoyNode *tail;
    int count;
    int nextTruckNumber;

public:
    Convoy();
    ~Convoy();

    void addTruck(SupplyBatch batch);
    bool removeTruck(string truckID);
    void displayForward();
    void displayBackward();
};

#endif
