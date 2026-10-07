#ifndef REGISTRY_H
#define REGISTRY_H

#include "Survivor.h"

class Registry
{
private:
    Survivor survivors[100];
    int count;

public:
    Registry();

    void addSurvivor(Survivor survivor);
    void displayAll();
    void searchByID(string id);
};

#endif