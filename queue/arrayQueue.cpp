#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear, *arr, n;

public:
    Queue()
    {
        cout << "Set the size for queue." << endl;
        cin >> n;
        arr = new int[n];
        front = rear = 0;
    }

    void enqueue()
    {
        if (rear >= n)
        {
            cout << "Overflow Condition." << endl;
            return;
        }

        int elem;
        cout << "Enter the element to be added in queue: " << endl;
        cin >> elem;

        if (rear == 0)
        {
            arr[0] = elem;
            rear++;
        }
        else
        {
            arr[rear] = elem;
            rear++;
        }
    }

    void dequeue()
    {
        if (rear == 0)
        {
            cout << "Underflow condition." << endl;
            return;
        }

        for (int i = 0; i < rear; i++)
        {
            arr[i - 1] = arr[i];
        }
        rear--;
        cout << "Dequeuing: " << arr[front] << endl;
    }

    void display()
    {
        for (int i = 0; i < rear; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    void peek()
    {
        if (rear == 0)
        {
            cout << "Empty queue." << endl;
            return;
        }

        cout << "Front is: " << arr[front] << endl;
    }

    

    ~Queue()
    {
        delete[] arr;
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