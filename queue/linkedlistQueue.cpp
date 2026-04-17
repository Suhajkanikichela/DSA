#include<iostream>
using namespace std;

class Queue
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *front, *rear, *p;
    int count, max;
    
public:
    Queue()
    {
        count = 0;
        cout<<"Set the max size for queue: "<<endl;
        cin>>max;
        front = rear = p = nullptr;
    }

    void enqueue()
    {
        if (count >= max)
        {
            cout<<"Overflow Condition."<<endl;
            return;
        }
        int value;
        cout<<"Enter the element to enqueue: "<<endl;
        cin>>value;
        p = new Node;
        p->data = value;
        p->next= nullptr;
        if (front == nullptr)
        {
            front = rear = p;
            count=1;
        }
        else
        {
            rear->next = p;
            rear = p;
            count++;
        }
        cout<<rear->data<<" enqued successfully."<<endl;
    }

    void dequeue()
    {
        if (count <= 0)
        {
            cout<<"Underflow Condition."<<endl;
            return;
        }
        p = front;
        cout<<p->data<<" dequed successfully."<<endl;
        if (count == 1)
        {
            
            delete p;
            front = rear = p = nullptr;
            count = 0;
        }
        else
        {
            front = front->next;
            delete p;
            count--;   
        }
    }

    void display()
    {
        if (count == 0)
        {
            cout<<"Empty Queue."<<endl;
            return;
        }
        p = front;
        cout<<"Display: "<<endl;
        while (p != nullptr)
        {
            cout<<p->data<<"\t";
            p = p->next;
        }
        cout<<endl;
    }

    void peek()
    {
        if (count == 0)
        {
            cout<<"Empty Queue."<<endl;
            return;
        }
        cout<<"Front of queue is: "<<front->data<<endl;
    }

    ~Queue()
    {
        while (front != nullptr)
        {
            p = front;
            front = front->next;
            delete p;
        }
    }
};

int main()
{
    Queue q;
    int choice;
    do
    {

        cout << "---------------" << endl;
        cout << "Menu." << endl;
        cout << "1. Enqueue." << endl;
        cout << "2. Dequeue." << endl;
        cout << "3. Peek." << endl;
        cout << "4. Display." << endl;
        cout << "5. Exit." << endl;
        cin >> choice;
        cout << "----------------" << endl;

        switch (choice)
        {
        case 1:
            q.enqueue();
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting the code." << endl;
            break;

        default:
            cout << "Enter a valid choice from 1-5" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}