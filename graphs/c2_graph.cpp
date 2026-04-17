#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph
{
private:
    unordered_map<string, unordered_set<string>> adjList;

public:
    Graph() {}

    void printGraph() const
    {
        for (auto it = adjList.begin(); it != adjList.end(); ++it)
        {
            cout << it->first << " : [";
            for (const auto& edge : it->second)
            {
                cout << edge << " ";
            }
            cout << "]" << endl;
        }
    }

    bool addVertex(const string& vertex)
    {
        if (adjList.count(vertex) == 0)
        {
            adjList[vertex]; // Add empty set
            return true;
        }
        return false;
    }

    bool addEdge(const string& vertex1, const string& vertex2)
    {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList[vertex1].insert(vertex2);
            adjList[vertex2].insert(vertex1);
            return true;
        }
        return false;
    }

    ~Graph() {}
};

int main()
{
    Graph *myG = new Graph();
    myG->addVertex("A");
    myG->addVertex("B");
    myG->addEdge("A", "B");

    myG->printGraph();

    delete myG; // Free memory

    return 0;
}
