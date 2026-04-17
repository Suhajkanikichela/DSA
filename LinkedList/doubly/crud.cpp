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

    void insert(int n)
    {
        int elem, pos;
        int count = 1;
        cout<<"Enter the position to insert element in: "<<endl;
        cin>>pos;
        cout<<"Enter the element to be inserted: "<<endl;
        cin>>elem;
        p = head;
        Node *newNode = new Node;
        newNode->prev = nullptr;
        newNode->data = elem;
        newNode->next = nullptr;

        if (pos <=1)
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        else if (pos >= n)
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else
        {

            while (count != pos -1 && p != nullptr)
            {
                p = p->next;
                count++;
            }
            newNode->next = p->next;
            newNode->prev = p;
            p->next->prev = newNode;
            p->next = newNode;
        }
    }

    void remove()
    {
        int elem;
        cout<<"Enter the element to be deleted: "<<endl;
        cin>>elem;
        Node *temp;
        if (head->data == elem)
        {
            temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            return;
        }
        if (tail->data == elem)
        {
            temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            return;
        }
        p = head;
        while (p != nullptr)
        {
            if (p->data == elem)
            {
                temp = p;
                p->next->prev = p->prev;
                p->prev->next = p->next;
                delete temp;
                return;
            }
            p = p->next;
        }
        cout<<"Element not found in the list."<<endl;
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
    int n, value;
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
    list.insert(n);
    list.display();
    list.remove();
    list.display();

    return 0;
}