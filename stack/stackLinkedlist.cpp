#include<iostream>
using namespace std;

class Stack
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head, *top, *p;
    int max, count;
    
public:
    Stack()
    {
        count = 0;
        cout<<"Set the max size for stack."<<endl;
        cin>>max;
        head = top = nullptr;
        p = nullptr;
    }

    void push()
    {
        if (count >= max)
        {
            cout<<"Overflow condition."<<endl;
            return;
        }
        int value;
        cout<<"Enter the element to be inserted: "<<endl;
        cin>>value;
        p = new Node;
        p->data = value;
        p->next = nullptr;
        if (head == nullptr)
        {
            head = p;
            top = p;
            count = 1;
        }
        else
        {
            top->next = p;
            top = p;
            count += 1;
        }
        cout<<top->data<<" pushed onto the stack successfully."<<endl;
    }

    void pop()
    {
        if (count <= 0)
        {
            cout<<"Underflow Condition."<<endl;
            return;
        }
        p = head;
        if (count == 1)
        {
            cout<<p->data<<" has been popped successfully."<<endl;
            delete p;
            p = head = top = nullptr;
            count = 0;
            return;
        }
        
        while (p->next->next != nullptr)
        {
            p = p->next;
        }
        Node *temp = top;
        top = p;
        cout<<temp->data<<" has been popped successfully."<<endl;
        delete temp;
        count--;
    }

    void peek()
    {
        if (count == 0)
        {
            cout<<"Empty Stack."<<endl;
            return;
        }
        cout<<top->data<<" is at top of stack."<<endl;
        
    }

    void display()
    {
        if (count == 0)
        {
            cout<<"Empty stack."<<endl;
            return;
        }
        
        p = head;
        cout<<"Display: "<<endl;
        while (p != nullptr)
        {
            cout<<p->data<<"\t";
            p = p->next;
        }
        cout<<endl;
    }

    ~Stack()
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
    Stack s;
    int choice;
    do
    {

        cout << "---------------" << endl;
        cout << "Menu." << endl;
        cout << "1. Push." << endl;
        cout << "2. Pop." << endl;
        cout << "3. Peek." << endl;
        cout << "4. Display." << endl;
        cout << "5. Exit." << endl;
        cin >> choice;
        cout << "----------------" << endl;

        switch (choice)
        {
        case 1:
            s.push();
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Exiting the code." << endl;
            break;

        default:
            cout << "Enter a valid choice from 1-4" << endl;
            break;
        }
    } while (choice != 5);

    
    return 0;
}