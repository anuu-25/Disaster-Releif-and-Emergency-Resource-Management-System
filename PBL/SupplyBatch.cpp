
#include <iostream>
#include "SupplyBatch.h"

using namespace std;

SupplyBatch::SupplyBatch()
{
    batchID = "";
    itemType = "";
    quantity = 0;
    destination = "";
}

SupplyBatch::SupplyBatch(string batchID, string itemType,
                         int quantity, string destination)
{
    this->batchID = batchID;
    this->itemType = itemType;
    this->quantity = quantity;
    this->destination = destination;
}

void SupplyBatch::display()
{
    cout << "Batch ID: " << batchID << endl;
    cout << "Item Type: " << itemType << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Destination: " << destination << endl;
}

string SupplyBatch::getBatchID()
{
    return batchID;
}

string SupplyBatch::getItemType()
{
    return itemType;
}

int SupplyBatch::getQuantity()
{
    return quantity;
}

string SupplyBatch::getDestination()
{
    return destination;
}

void SupplyBatch::setQuantity(int quantity)
{
    this->quantity = quantity;
}
