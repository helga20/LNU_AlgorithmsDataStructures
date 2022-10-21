#pragma once
class Graph
{
private:
    int** adjMatrix;
    int numVertices;
    int distance;

public:
    Graph(int numVertices);
    ~Graph();

    void addEdge(int i, int j, int d);
    void printOn();
    void dijkstra();
};

