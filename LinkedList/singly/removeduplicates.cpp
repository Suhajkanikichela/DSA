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

    void removeDuplicates()
    {
        p = head;
        Node *q = nullptr;
        Node *temp = nullptr;

        while (p->next != nullptr)
        {
            q = p;
            while (q->next != nullptr)
            {
                if (q->next->data == p->data)
                {
                    temp = q->next;
                    q->next = q->next->next;
                    delete temp;
                }
                else
                {
                    q = q->next;
                }
            }
            p = p->next;
        }
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
    list.removeDuplicates();
    list.display();
    return 0;
}