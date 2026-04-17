#include <iostream>
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

public:
    Tree()
    {
        root = nullptr;
    }

    int getinput()
    {
        int data;
        cout << "Enter the value: " << endl;
        cin >> data;
        return data;
    }

    void create(int data)
    {
        Node *t, *r, *p;
        p = new Node{data, nullptr, nullptr};
        if (root == nullptr)
        {
            root = p;
            return;
        }
        t = root;

        while (t != nullptr)
        {
            r = t;
            if (data > t->data)
            {
                t = t->rchild;
                if (t == nullptr)
                {
                    r->rchild = p;
                    return;
                }
            }
            else if (data < t->data)
            {
                t = t->lchild;
                if (t == nullptr)
                {
                    r->lchild = p;
                    return;
                }
            }
            else
            {
                delete p;
                return;
            }
        }
    }

    void inOrder(Node *node)
    {
        if (node)
        {
            inOrder(node->lchild);
            cout << node->data << "\t";
            inOrder(node->rchild);
        }
    }

    void display()
    {
        cout << "\nIn Order: " << endl;
        inOrder(root);
    }

    int search(int data)
    {
        Node *t = root;
        while (t != nullptr)
        {
            if (data == t->data)
            {
                return t->data;
            }
            else if (data > t->data)
            {
                t = t->rchild;
            }
            else
            {
                t = t->lchild;
            }
        }
        return -1;
    }

    Node* findMin(Node* node)
    {
        while (node && node->lchild != nullptr)
        {
            node = node->lchild;
        }
        return node;
    }

    Node* deleteNode(Node* node, int data)
    {
        if (node == nullptr) return node;

        if (data < node->data)
        {
            node->lchild = deleteNode(node->lchild, data);
        }
        else if (data > node->data)
        {
            node->rchild = deleteNode(node->rchild, data);
        }
        else
        {
            // Case 1: No child (leaf node)
            if (node->lchild == nullptr && node->rchild == nullptr)
            {
                delete node;
                return nullptr;
            }
            // Case 2: One child
            else if (node->lchild == nullptr)
            {
                Node* temp = node->rchild;
                delete node;
                return temp;
            }
            else if (node->rchild == nullptr)
            {
                Node* temp = node->lchild;
                delete node;
                return temp;
            }
            // Case 3: Two children
            else
            {
                Node* temp = findMin(node->rchild); // Inorder successor
                node->data = temp->data;
                node->rchild = deleteNode(node->rchild, temp->data);
            }
        }
        return node;
    }

    void remove(int data)
    {
        root = deleteNode(root, data);
    }

    void clear(Node *node)
    {
        if (node)
        {
            clear(node->lchild);
            clear(node->rchild);
            delete node;
        }
    }

    ~Tree()
    {
        clear(root);
    }
};

int main()
{
    Tree tr;
    int num;
    cout << "Enter the number of inputs: " << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        tr.create(tr.getinput());
    }

    tr.display();

    int searchValue = tr.getinput(); 
    int result = tr.search(searchValue); 

    if (result != -1) {
        cout << "Element " << result << " found." << endl; 
    } else {
        cout << "Element not found." << endl;
    }

    cout << "Enter the value to delete: ";
    int deleteValue = tr.getinput();
    tr.remove(deleteValue);

    cout << "Tree after deletion:" << endl;
    tr.display();

    return 0;
}
