#include<iostream>
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

    void checkSorted()
    {
        int elem;
        elem = head->data;
        p = head;
        while (p != nullptr)
        {
            if (elem <= p->data)
            {
                elem = p->data;
            }
            else
            {
                cout<<"Unsorted linked list."<<endl;
                return;
            }
            p = p->next;
        }
        cout<<"Linked list is sorted."<<endl;        
    }

    void display()
    {
        p = head;
        while (p != nullptr)
        {
            cout<<p->data<<"\t";
            p = p->next;
        }
        cout<<endl;
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
    cout<<"Enter the number of inputs: "<<endl;
    cin>>n;
    LinkedList list;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the value for "<<i+1<<": "<<endl;
        cin>>value;
        list.append(value);
    }
    list.display();
    list.checkSorted();
    return 0;
}