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
        head = nullptr;
        tail = nullptr;
        p = nullptr;
    }

    void append(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
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

    void max()
    {
        int max = head->data;
        p = head;
        while (p != nullptr)
        {
            if (p->data > max)
            {
                max = p->data;
            }
            p = p->next;
        }
        cout << "The maximum element of linked list is: " << max << endl;
    }

    void CountAndSum()
    {
        int count = 0, sum = 0;
        p = head;
        while (p != nullptr)
        {
            sum += p->data;
            count++;
            p = p->next;
        }
        cout << "The number of nodes are: " << count << endl;
        cout << "The sum of all elements = " << sum << endl;
    }

    void linearSearch()
    {
        int elem, pos = 1;
        cout << "Enter the element to be searched: " << endl;
        cin >> elem;
        p = head;
        while (p != nullptr)
        {
            if (p->data == elem)
            {
                cout << "Element found at position " << pos << " of linked list" << endl;
                return;
            }
            p = p->next;
            pos++;
        }
        cout << "Element not found." << endl;
    }

    ~LinkedList()
    {
        Node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    int n, value;
    cout << "Enter the number of values for input: " << endl;
    cin >> n;

    LinkedList list;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value for " << i + 1 << ": " << endl;
        cin >> value;
        list.append(value);
    }

    list.display();
    list.max();
    list.CountAndSum();
    list.linearSearch();

    return 0;
}