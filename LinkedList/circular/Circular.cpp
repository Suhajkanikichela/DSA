#include<iostream>
using namespace std;

class Circular
{
private:
    struct Node
    {
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
        p->data = value;
        p->next = nullptr;
        if (head == nullptr)
        {
            head = p;
            tail = p;
            head->next = head;
        }
        else
        {
            tail->next = p;
            tail = p;
            tail->next = head;
        }
    }

    void insert()
    {
        int elem, pos;
        cout<<"Enter the psition to insert element in: "<<endl;
        cin>>pos;
        cout<<"Enter the element to be inserted: "<<endl;
        cin>>elem;
        Node *newNode = new Node;
        newNode->data = elem;
        newNode->next = nullptr;
        int count = 1;
        p = head;
        if (pos <= 1 )
        {
            tail->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        else
        {
            do
            {
                if (count == pos-1)
                {
                    newNode->next = p->next;
                    p->next = newNode;
                    return;
                }
                p = p->next;
                count++;
            } while (p != head);
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    void remove()
    {
        int elem;
        cout<<"Enter the element to be deleted: "<<endl;
        cin>>elem;
        p = head;
        Node *temp;
        if (head->data == elem)
        {
            temp = head;
            head = head->next;
            tail->next = head;
            delete temp; 
            return;
        }
        do
        {
            if (p->next->data == elem)
            {
                temp = p->next;
                p->next = p->next->next;
                delete temp;
                return;
            }
            p = p->next;
        } while (p != head);
        cout<<"Element not found in the list."<<endl;
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
    cout<<"Enter the number for size: "<<endl;
    cin>>n;
    Circular list;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the value for "<<i+1<<": "<<endl;
        cin>>value;
        list.append(value);
    }
    list.display();
    list.insert();
    list.display();
    list.remove();
    list.display();

    return 0;
}