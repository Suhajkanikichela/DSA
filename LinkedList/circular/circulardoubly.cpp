#include<iostream>
using namespace std;

class Circular
{
private:
    struct Node
    {
        Node *prev;
        int data;
        Node *next;
    };
    Node *head, *tail, *p;
    
public:
    Circular()
    {
        head = tail = nullptr;
    }

    void append(int value)
    {
        p = new Node;
        p->prev = nullptr;
        p->data = value;
        p->next = nullptr;

        if (head == nullptr)
        {
            head = tail = p;
            head->next = tail;
            tail->prev = head;
        }
        else
        {
            p->prev = tail;
            tail->next = p;
            tail = p;
            tail->next = head;
            head->prev = tail;
        }
    }

    void display()
    {
        cout<<"Display: "<<endl;
        p = head;
        do
        {
            cout<<p->data<<"\t";
            p = p->next;
        } while (p != head);
        cout<<endl;
    }

    ~Circular()
    {
        tail->next = nullptr;
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
    cout<<"Enter the number of inputs: "<<endl;
    cin>>n;
    Circular doubly;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the value for "<<i+1<<": "<<endl;
        cin>>value;
        doubly.append(value);
    }
    doubly.display();
    
    return 0;
}