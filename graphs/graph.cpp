#include <iostream>
using namespace std;

class Graph
{
private:
    struct Node
    {
        int vortex;
        Node *next;
    };
    int vertices;
    Node **adjlist;

    Node *createNode(int v)
    {
        Node *newNode = new Node{v, nullptr};
        return newNode;
    }

public:
    Graph(int v)
    {
        vertices = v;
        adjlist = new Node *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            adjlist[i] = nullptr;
        }
    }

    void addEdge(int u, int v)
    {
        if (u >= vertices || v >= vertices || u < 0 || v < 0) 
        {
            cout << "Error: Invalid vertex index.\n";
            return;
        }

        Node *newNode = createNode(v);
        newNode->next = adjlist[u];
        adjlist[u] = newNode;

        newNode = createNode(u);
        newNode->next = adjlist[v];
        adjlist[v] = newNode;
    }

    void display()
    {
        cout << "\nRepresentation using adjecency list: " << endl;
        for (int i = 0; i < vertices; i++)
        {
            cout << "Vortex: " << i << ": ";
            Node *temp = adjlist[i];
            while (temp)
            {
                cout << temp->vortex << " -> ";
                temp = temp->next;
            }
            cout <<"NULL" << endl;
        }
    }

    ~Graph()
    {
        Node *temp;
        for (int i = 0; i < vertices; i++)
        {
            temp = adjlist[i];
            while (temp)
            {
                Node *del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete[] adjlist;
    }
};

int main()
{
    int vertices, edges;
    cout<<"Enter number of vertices: "<<endl;
    cin>>vertices;

    Graph g(vertices);
    cout << "Enter the number of edges: " << endl;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " (u,v): ";
        cin >> u >> v;
        g.addEdge(u, v);
    }
    
    g.display();

    return 0;
}