#include<iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    Node *root;
public:
    BST()
    {
        // Node *newNode = new Node(value);
        // root = newNode;
        root = nullptr;
    }

    bool insert(int value)
    {
        Node *newNode = new Node{value};
        if (!root)
        {
            root = newNode;
            return true;
        }
        Node *temp = root;
        while (true)
        {
            if (newNode->value == temp->value)
            {
                return false;
            }
            if (newNode->value < temp->value)
            {
                if (!temp->left)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else
            {
                if (!temp->right)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }

    bool contains(int value)
    {
        if (!root)
        {
            return false;
        }
        Node *temp = root;
        while (temp)
        {
            if (value > temp->value)
            {
                temp = temp->right;
            }
            else if (value < temp->value)
            {
                temp = temp->left;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    void free(Node *node)
    {
        free(node->left);
        free(node->right);
        delete node;
    }

    void inOrder(Node *node)
    {
        inOrder(node->left);
        cout<<node->value<<"\t";
        inOrder(node->right);
    }

    void display()
    {
        inOrder(root);
    }

    ~BST()
    {
        free(root);
    }
};

int main()
{
    
    return 0;
}