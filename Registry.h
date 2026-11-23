#ifndef REGISTRY_H
#define REGISTRY_H

#include "Survivor.h"

class Registry
{
private:
    struct Node
    {
        Survivor data;
        Node *next;
    };

    Node *head;

public:
    Registry();
    ~Registry();

    void addSurvivor(Survivor s);
    void displayAll() const;
    bool searchByName(string name) const;
    bool searchSurvivor(int id) const;
    bool updateSeverity(int id, int severity);
    void saveToFile() const;
    void loadFromFile();
    bool isEmpty() const;
    int getLastID() const;
    int copySurvivors(Survivor list[], int limit) const;
};

#endif
