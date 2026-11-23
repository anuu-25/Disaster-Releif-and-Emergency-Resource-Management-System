#include "Registry.h"
#include <fstream>
#include <sstream>

Registry::Registry()
{
    head = NULL;
}

Registry::~Registry()
{
    Node *P = head;

    while (P != NULL)
    {
        Node *R = P;
        P = P->next;
        delete R;
    }
}

void Registry::addSurvivor(Survivor s)
{
    Node *P = new Node;
    P->data = s;
    P->next = NULL;

    if (head == NULL)
    {
        head = P;
    }
    else
    {
        Node *R = head;

        while (R->next != NULL)
        {
            R = R->next;
        }

        R->next = P;
    }
}

void Registry::displayAll() const
{
    Node *P = head;

    if (P == NULL)
    {
        cout << "No survivor records found.\n";
        return;
    }

    while (P != NULL)
    {
        P->data.display();
        P = P->next;
    }
}

bool Registry::searchSurvivor(int id) const
{
    Node *P = head;

    while (P != NULL)
    {
        if (P->data.getID() == id)
        {
            P->data.display();
            return true;
        }

        P = P->next;
    }

    cout << "Survivor not found.\n";
    return false;
}
bool Registry::searchByName(string name) const
{
    Node *P = head;

    while (P != NULL)
    {
        if (P->data.getName() == name)
        {
            P->data.display();
            return true;
        }

        P = P->next;
    }

    cout << "Survivor not found." << endl;

    return false;
}

bool Registry::updateSeverity(int id, int severity)
{
    Node *P = head;

    while (P != NULL)
    {
        if (P->data.getID() == id)
        {
            P->data.setSeverity(severity);
            cout << "Severity updated successfully.\n";
            return true;
        }

        P = P->next;
    }

    cout << "Survivor not found.\n";
    return false;
}

void Registry::saveToFile() const
{
    ofstream fout("data/survivors.txt");
    Node *P = head;

    while (P != NULL)
    {
        fout << P->data.getID() << "|"
             << P->data.getName() << "|"
             << P->data.getAge() << "|"
             << P->data.getSeverity() << "|"
             << P->data.getJunction() << "|"
             << P->data.getCondition() << endl;

        P = P->next;
    }

    fout.close();
    cout << "Survivor records saved to data/survivors.txt.\n";
}

void Registry::loadFromFile()
{
    ifstream fin("data/survivors.txt");

    if (!fin)
    {
        cout << "No saved survivor file found.\n";
        return;
    }

    string line;

    while (getline(fin, line))
    {
        stringstream ss(line);
        string idText, name, ageText, severityText, junction, condition;

        getline(ss, idText, '|');
        getline(ss, name, '|');
        getline(ss, ageText, '|');
        getline(ss, severityText, '|');
        getline(ss, junction, '|');
        getline(ss, condition, '|');

        if (idText != "" && name != "")
        {
            int id = stoi(idText);
            int age = stoi(ageText);
            int severity = stoi(severityText);
            addSurvivor(Survivor(id, name, age, severity, junction, condition));
        }
    }

    fin.close();
    cout << "Saved survivor records loaded.\n";
}

bool Registry::isEmpty() const
{
    return head == NULL;
}

int Registry::getLastID() const
{
    int lastID = 1000;
    Node *P = head;

    while (P != NULL)
    {
        if (P->data.getID() > lastID)
        {
            lastID = P->data.getID();
        }
        P = P->next;
    }

    return lastID;
}

int Registry::copySurvivors(Survivor list[], int limit) const
{
    int count = 0;
    Node *P = head;

    while (P != NULL && count < limit)
    {
        list[count] = P->data;
        count++;
        P = P->next;
    }

    return count;
}
