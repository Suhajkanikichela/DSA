#include<iostream>
using namespace std;

class Doubly
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
    Doubly()
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
        }
        else
        {
            p->prev = tail;
            tail->next = p;
            tail = p;
        }
    }

    void display()
    {
        p = head;
        cout<<"Display: "<<endl;
        while (p != nullptr)
        {
            cout<<p->data<<"\t";
            p = p->next;
        }
        cout<<endl;
    }

    void reverse()
    {
        Node *temp;
        p = head;
        while (p != nullptr)
        {
            temp = p->prev;
            p->prev = p->next;
            p->next = temp;
            p = p->prev;
        }
        temp = head;
        head = tail;
        tail = temp;
    }

    ~Doubly()
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
    int  n, value;
    cout<<"Enter the number of inputs: "<<endl;
    cin>>n;
    Doubly list;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the value for "<<i+1<<": "<<endl;
        cin>>value;
        list.append(value);
    }
    list.display();
    list.reverse();
    list.display();
    
    return 0;
}