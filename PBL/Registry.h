#ifndef REGISTRY_H
#define REGISTRY_H
#include "survivor.h"

class Registry
{
private:
    Survivor survivors[100];
    int count;

public:
    Registry();

    bool addSurvivor(Survivor survivor);
    void displayAll();
    void searchByID(string id);
};

#endif