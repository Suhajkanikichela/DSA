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
        head = nullptr;
        tail = nullptr;
        p = nullptr;
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
        while (p != nullptr)
        {
            cout<<p->data<<"\t";
            p = p->next;
        }
        cout<<endl;
    }

    void insert()
    {
        int elem;
        cout<<"Enter the element to be inserted: "<<endl;
        cin>>elem;
        p = new Node;
        p->data = elem;
        p->next = nullptr;
        if (head == nullptr || elem < head->data)
        {
            p->next = head;
            head = p;
        }
        else if (elem > tail->data)
        {
            tail->next = p;
            tail = p;
        }
        else
        {
            Node *prev = head;
            while (prev->next != nullptr && prev->next->data < elem) 
            {
                prev = prev->next;
            } 
            p->next = prev->next;
            prev->next = p;
        }
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
        cout<<"Enter the value of "<<i+1<<": "<<endl;
        cin>>value;
        list.append(value);
    }
    list.display();
    list.insert();
    list.display();

    return 0;
}