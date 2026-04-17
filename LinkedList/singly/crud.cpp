#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head, *tail, *p;

public:
    LinkedList()
    {
        head = tail = p = nullptr;
    }

    void append(int value)
    {
        p = new Node;
        p->data = value;
        p->next = nullptr;

        if (head == nullptr)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }

    void insert(int n)
    {
        int elem, pos;
        int count = 1;
        cout << "Enter the position to insert element in: " << endl;
        cin >> pos;
        cout << "Enter the element to be inserted: " << endl;
        cin >> elem;
        p = head;
        Node *newNode = new Node;
        newNode->data = elem;
        newNode->next = nullptr;
        if (pos <= 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else if (pos > n)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            while (count != pos - 1 && p != nullptr)
            {
                p = p->next;
                count++;
            }
            newNode->next = p->next;
            p->next = newNode;
        }
    }

    void remove()
    {
        Node *temp;
        int elem;
        cout << "Enter the element to be deleted: " << endl;
        cin >> elem;
        if (head->data == elem)
        {
            temp = head;
            head = head->next;
            delete temp;
            return;
        }
        p = head;
        while (p->next != nullptr)
        {
            if (p->next->data == elem)
            {
                temp = p->next;
                p->next = p->next->next;
                delete temp;
                return;
            }
            p = p->next;
        }
        cout << "Element not found in the list." << endl;
    }

    void display()
    {
        p = head;
        while (p != nullptr)
        {
            cout << p->data << "\t";
            p = p->next;
        }
        cout << endl;
    }

    ~LinkedList()
    {
        while (head != nullptr)
        {
            p = head;
            head = head->next;
            delete p;
        }
    }
};

int main()
{
    int n, value;
    cout << "Enter the number of inputs: " << endl;
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value for " << i + 1 << ": " << endl;
        cin >> value;
        list.append(value);
    }
    list.display();
    list.insert(n);
    list.display();
    list.remove();
    list.display();

    return 0;
}