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
        return front==rear;
    }

    void create()
    {
        int data;
        cout<<"Enter the value for root node: "<<endl;
        cin>>data;
        root = new Node{data, nullptr, nullptr};
        enqueue(root);

        while (!isEmpty())
        {
            Node *p = dequeue();
            cout<<"Enter the value for left child of "<<p->data<<" (or -1 for no child): "<<endl;
            cin>>data;
            if (data != -1)
            {
                p->lchild = new Node{data, nullptr, nullptr};
                enqueue(p->lchild);
            }
            cout<<"Enter the value for right child of "<<p->data<<" (or -1 for no child): "<<endl;
            cin>>data;
            if (data != -1)
            {
                p->rchild = new Node{data, nullptr, nullptr};
                enqueue(p->rchild);
            }
        }
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

    int count(Node *p)
    {
        int x = 0, y = 0;
        if (p)
        {
            x = count(p->lchild);
            y = count(p->rchild);
            return x + y + 1;
        }
        return 0;
    }

    int leafCount(Node *p)
    {
        if (!p)
        {
            return 0;
        }
        if (!p->lchild && !p->rchild)
        {
            return 1;
        }
        return leafCount(p->lchild) + leafCount(p->rchild);
    }

    void getCount()
    {
        cout << "Node Count: " << count(root) << endl;
        cout << "Leaf node count: " << leafCount(root) << endl;
    }
    
    ~Tree()
    {
        free(root);
        delete[] q;
    }
};

int main()
{
    Tree t;
    t.create();
    t.getCount();
    
    return 0;
}