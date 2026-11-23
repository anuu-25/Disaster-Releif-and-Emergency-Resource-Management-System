#include "RoadNetwork.h"
#include <iostream>
using namespace std;

RoadNetwork::RoadNetwork()
{
    // 0 means that the road is blocked or not connected.
    int roads[5][5] = {
        {0, 4, 2, 0, 0},
        {4, 0, 1, 5, 0},
        {2, 1, 0, 8, 10},
        {0, 5, 8, 0, 2},
        {0, 0, 10, 2, 0}
    };

    for (int P = 0; P < 5; P++)
    {
        for (int R = 0; R < 5; R++)
        {
            graph[P][R] = roads[P][R];
        }
    }
}

void RoadNetwork::displayRoads() const
{
    cout << "\nROAD DISTANCE TABLE (0 = no direct road)\n";
    cout << "     J1  J2  J3  J4  J5\n";

    for (int P = 0; P < 5; P++)
    {
        cout << "J" << P + 1 << "   ";

        for (int R = 0; R < 5; R++)
        {
            cout << graph[P][R] << "   ";
        }

        cout << endl;
    }
}

void RoadNetwork::findSafeRoute(int start, int destination) const
{
    if (start < 1 || start > 5 || destination < 1 || destination > 5)
    {
        cout << "Please select junctions from J1 to J5.\n";
        return;
    }

    int distance[5];
    bool visited[5];
    int parent[5];

    for (int P = 0; P < 5; P++)
    {
        distance[P] = 999;
        visited[P] = false;
        parent[P] = -1;
    }

    distance[start - 1] = 0;

    for (int P = 0; P < 5; P++)
    {
        int minDistance = 999;
        int current = -1;

        for (int R = 0; R < 5; R++)
        {
            if (!visited[R] && distance[R] < minDistance)
            {
                minDistance = distance[R];
                current = R;
            }
        }

        if (current == -1)
        {
            break;
        }

        visited[current] = true;

        for (int R = 0; R < 5; R++)
        {
            if (graph[current][R] > 0 && !visited[R])
            {
                int newDistance = distance[current] + graph[current][R];

                if (newDistance < distance[R])
                {
                    distance[R] = newDistance;
                    parent[R] = current;
                }
            }
        }
    }

    int end = destination - 1;

    if (distance[end] == 999)
    {
        cout << "No safe route is available.\n";
        return;
    }

    int path[5];
    int count = 0;
    int P = end;

    while (P != -1)
    {
        path[count] = P;
        count++;
        P = parent[P];
    }

    cout << "Shortest route: ";

    for (int R = count - 1; R >= 0; R--)
    {
        cout << "J" << path[R] + 1;

        if (R > 0)
        {
            cout << " -> ";
        }
    }

    cout << "\nTotal distance: " << distance[end] << " km\n";
}
