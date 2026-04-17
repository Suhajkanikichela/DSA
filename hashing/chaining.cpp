#include <iostream>
using namespace std;

class Chained
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *table[10];

public:
    Chained()
    {
        for (int i = 0; i < 10; i++)
        {
            table[i] = nullptr;
        }
    }

    int hashkey(int key)
    {
        return key % 10;
    }

    void insert(int key)
    {
        Node *newNode = new Node{key, nullptr};
        int index = hashkey(key);
        if (table[index] == nullptr || table[index]->data >= key)
        {
            newNode->next = table[index];
            table[index] = newNode;
        }
        else
        {
            Node *prev = table[index];
            while ((prev->next) && (prev->next->data < key))
            {
                prev = prev->next;
            }
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }

    bool search(int key)
    {
        int index = hashkey(key);
        Node *temp = table[index];
        while (temp)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void remove(int key)
    {
        int index = hashkey(key);
        Node *temp = table[index], *prev;
        while (temp != nullptr && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "Element not found." << endl;
            return;
        }
        if (prev)
        {
            prev->next = temp->next;
        }
        else
        {
            table[index] = temp->next;
        }
        delete temp;
        cout << "Key " << key << " deleted." << endl;
    }

    void display()
    {
        cout << "Display: " << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << "Index: " << i << ": ";
            Node *temp = table[i];
            while (temp)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
    }

    ~Chained()
    {
        Node *temp;
        for (int i = 0; i < 10; i++)
        {
            temp = table[i];
            while (temp)
            {
                Node *del = temp;
                temp = temp->next;
                delete del;
            }
        }
    }
};

int main()
{
    Chained table;
    int num;
    cout << "Enter the num for input: " << endl;
    cin >> num;
    int *arr = new int[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Enter element " << i + 1 << " for array: " << endl;
        cin >> arr[i];
        table.insert(arr[i]);
    }

    cout << "Hash table: " << endl;
    table.display();

    int value;
    cout << "Enter element to search: " << endl;
    cin >> value;
    if (table.search(value))
    {
        cout << "Element " << value << " found in the hashtable." << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    cout << "Enter the element to be deleted: " << endl;
    cin >> value;
    table.remove(value);
    table.display();

    delete[] arr;
    return 0;
}