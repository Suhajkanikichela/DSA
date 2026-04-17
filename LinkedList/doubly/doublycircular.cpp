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
            tail->prev = head;
            head->next = tail;
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
        p = head;
        cout<<"Display: "<<endl;
        do
        {
            cout<<p->data<<"\t";
            p = p->next;
        } while (p != head);
        
    }

    ~Doubly()
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
    cout<<"Enter the number for input: "<<endl;
    cin>>n;
    Doubly circular;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the value for "<<i+1<<": "<<endl;
        cin>>value;
        circular.append(value);
    }
    circular.display();
    
    return 0;
}