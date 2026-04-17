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
        p = head = tail = nullptr;
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

    void display()
    {
        p = head;
        cout << "Display: " << endl;
        while (p != nullptr)
        {
            cout << p->data << "\t";
            p = p->next;
        }
        cout << endl;
    }

    void reverse()
    {
        Node *q, *r;
        q = r = nullptr;
        p = head;
        while (p != nullptr)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;
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
    cout << "Enter the number of elements for linked list: " << endl;
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value for element " << i + 1 << " of list: " << endl;
        cin >> value;
        list.append(value);
    }
    list.display();
    list.reverse();
    list.display();

    return 0;
}