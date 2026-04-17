#include<iostream>
using namespace std;

class Tree
{
private:
    struct Node
    {
        int data;
        Node *lchild;
        Node *rchild;
    };
    Node *root;
    int front, rear;
    Node **q;

public:
    Tree()
    {
        root = nullptr;
        front = rear = -1;
        q = new Node*[100];
    }

    void enqueue(Node *node)
    {
        q[++rear] = node; 
    }
    
    Node *dequeue()
    {
        return q[++front];
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void createTree()
    {
        int value;
        cout<<"Enter the value for root: "<<endl;
        cin>>value;
        root = new Node{value, nullptr, nullptr};
        enqueue(root);

        while (!isEmpty())
        {
            Node *currentNode = dequeue();
            cout<<"Enter the value for left child of "<<currentNode->data<<" or -1 for no child: "<<endl;
            cin>>value;
            if (value != -1)
            {
                currentNode->lchild = new Node{value, nullptr, nullptr};
                enqueue(currentNode->lchild);
            }

            cout<<"Enter the value for right child of "<<currentNode->data<<" or -1 for no child: "<<endl;
            cin>>value;
            if (value != -1)
            {
                currentNode->rchild = new Node{value, nullptr, nullptr};
                enqueue(currentNode->rchild);
            } 
        }
    }

    void bfs()
    {
        front = rear = -1;
        enqueue(root);

        while (!isEmpty())
        { 
            Node *currentNode = dequeue();
            cout<<currentNode->data<<"\t";

            if (currentNode->lchild)
            {
                enqueue(currentNode->lchild);
            }
            if (currentNode->rchild)
            {
                enqueue(currentNode->rchild);
            }
        }
    }

    void display()
    {
        cout<<"\n Breadth First Search or level order search: "<<endl;
        bfs();
    }

    void free(Node *node)
    {
        if (node)
        {
            free(node->lchild);
            free(node->rchild);
            delete node;
        }
        
    }
    ~Tree()
    {
        free(root);
        delete[] q;
    }
};

int main()
{
    Tree tree;
    tree.createTree();
    tree.display();
    
    return 0;
}