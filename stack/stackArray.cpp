#include <iostream>
using namespace std;

class Stack
{
private:
    int n;
    int *arr;
    int top;

public:
    Stack()
    {
        cout << "Enter the size for stack: " << endl;
        cin >> n;
        arr = new int[n];
        top = 0;
    }

    void push()
    {
        if (top >= n)
        {
            cout << "Overflow Condition." << endl;
            return;
        }
        int elem;
        cout << "Enter the element to be pushed: " << endl;
        cin >> elem;
        arr[top] = elem;
        top++;
    }

    void pop()
    {
        if (top <= 0)
        {
            cout << "Underflow Condition." << endl;
            return;
        }
        top--;
        cout << "Element popped: " << arr[top] << endl;
    }

    void peek()
    {
        if (top <= 0)
        {
            cout << "Empty Stack." << endl;
            return;
        }
        cout << "Top of stack is: " << arr[top - 1] << endl;
    }

    void display()
    {
        if (top <= 0)
        {
            cout << "Empty Stack." << endl;
            return;
        }
        cout << "Display: " << endl;
        for (int i = 0; i < top; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    ~Stack()
    {
        delete[] arr;
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