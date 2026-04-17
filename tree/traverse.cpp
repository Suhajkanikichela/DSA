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
        q =new Node*[100];
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
            cout<<"Enter the value for left child of "<<currentNode->data<<" (or -1 for no left child): "<<endl;
            cin>>value;
            if (value != -1)
            {
                currentNode->lchild = new Node{value, nullptr, nullptr};
                enqueue(currentNode->lchild);
            }

            cout<<"Enter the value for right child of "<<currentNode->data<<" (or -1 for no right child): "<<endl;
            cin>>value;
            if (value != -1)
            {
                currentNode->rchild = new Node{value, nullptr, nullptr};
                enqueue(currentNode->rchild);
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

    void preOrder(Node *p)
    {
        if (p)
        {
            cout<<p->data<<"\t";
            preOrder(p->lchild);
            preOrder(p->rchild);
        }
    }

    void inOrder(Node *p)
    {
        if (p)
        {
            inOrder(p->lchild);
            cout<<p->data<<"\t";
            inOrder(p->rchild);
        }
    }
    void postOrder(Node *p)
    {
        if (p)
        {
            postOrder(p->lchild);
            postOrder(p->rchild);
            cout<<p->data<<"\t";
        }
    }

    void levelOrder()
    {
        front = rear = -1;
        enqueue(root);

        while (!isEmpty())
        {
            Node *currentNode  = dequeue();
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
        cout<<"-- Pre order --"<<endl;
        preOrder(root);
        cout<<"\n-- In Order --"<<endl;
        inOrder(root);
        cout<<"\n-- Post Order --"<<endl; 
        postOrder(root);
        cout<<"\n-- Level Order --"<<endl;
        levelOrder();
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