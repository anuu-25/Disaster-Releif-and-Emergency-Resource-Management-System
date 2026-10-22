#ifndef SUPPLYBATCH_H
#define SUPPLYBATCH_H

#include <iostream>
#include <string>
using namespace std;

class SupplyBatch
{
private:
    string batchID;
    string itemType;
    int quantity;
    string destination;

public:
     SupplyBatch();
     SupplyBatch(string batchID, string itemType, int quantity, string destination);
    
    void display();

    string getBatchID();
    string getItemType();
    int getQuantity();
    string getDestination();

    void setQuantity(int quantity);

    
};

#endif