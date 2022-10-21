#include <iostream>
#include "graph.h"
#include <queue>
using namespace std;

Graph::Graph(int numVertices)
{
    this->numVertices = numVertices;

    adjMatrix = new int* [numVertices];
    for (int i = 1; i < numVertices; i++)
    {
        adjMatrix[i] = new int[numVertices];
        for (int j = 1; j < numVertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

Graph::~Graph()
{
    for (int i = 1; i < numVertices; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

void Graph::addEdge(int i, int j, int d)
{
    adjMatrix[i][j] = d;
    adjMatrix[j][i] = d;
}

void Graph::printOn()
{
    cout << "Матриця суміжності: \n\n";
    for (int i = 1; i < numVertices; i++)
    {
        cout << i << " : ";
        for (int j = 1; j < numVertices; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Graph::dijkstra()
{
    bool visite[100];
    int dist[100];

    for (int i = 0; i < numVertices; ++i)
    {
        visite[i] = false;
        dist[i] = INT_MAX;
    }

    visite[1] = true;
    dist[1] = 0;

    queue<int>q;
    q.push(1);

    while (!q.empty())
    {
        int vetrex = q.front(); q.pop();

        for (int j = 1; j < numVertices; ++j)
        {
            if (!visite[j] && adjMatrix[vetrex][j] && adjMatrix[vetrex][j] + dist[vetrex] < dist[j])
            {
                dist[j] = adjMatrix[vetrex][j] + dist[vetrex];
                q.push(j);
            }

        }
    }
    cout << "\n";

    cout << "*Алгоритм Дейкстри*\n\n";

    for (int j = 1; j < numVertices; ++j)
    {
        cout << dist[j] << " - найкоротший шлях між вершинами\n";
    }
}

