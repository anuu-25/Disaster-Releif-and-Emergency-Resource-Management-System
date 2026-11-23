#ifndef ROADNETWORK_H
#define ROADNETWORK_H

class RoadNetwork
{
private:
    int graph[5][5];

public:
    RoadNetwork();
    void displayRoads() const;
    void findSafeRoute(int start, int destination) const;
};

#endif
