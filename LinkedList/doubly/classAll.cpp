#include <iostream>
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
    int size;

public:
    Doubly()
    {
        head = tail = nullptr;
        p = nullptr;
        size = 0;
    }

    void getinput()
    {
        int value;
        cout << "Enter the value of the element: " << endl;
        cin >> value;
        append(value);
    }

    void append(int value)
    {
        p = new Node;
        p->prev = nullptr;
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
            p->prev = tail;
            tail = p;
        }
        size++;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "Empty list." << endl;
            return;
        }
        p = head;
        cout << "Display: " << endl;
        while (p != nullptr)
        {
            cout << p->data << "\t";
            p = p->next;
        }
        cout << endl;
    }

    int getcount()
    {
        return size;
    }

    void insert(int size)
    {
        int elem, pos;
        cout << "Enter a valid position to insert element in: " << endl;
        cin >> pos;
        cout << "Enter the element to be inserted: " << endl;
        cin >> elem;

        Node *newNode = new Node;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        newNode->data = elem;
        if (head == nullptr)
        {
            head = tail = newNode;
            size++;
            return;
        }

        if (pos <= 1)
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        else if (pos > size)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            int index = 1;
            p = head;
            while (index < pos - 1)
            {
                p = p->next;
                index++;
            }
            newNode->prev = p;
            newNode->next = p->next;
            if (p->next != nullptr)
            {
                p->next->prev = newNode;
            }
            p->next = newNode;
        }
        size++;
    }

    void remove()
    {
        if (size == 0)
        {
            cout << "Empty list." << endl;
            return;
        }

        int elem;
        cout << "Enter the element to be deleted: " << endl;
        cin >> elem;
        if (head->data == elem)
        {
            p = head;
            head = head->next;
            head->prev = nullptr;
            delete p;
            size--;
            return;
        }
        if (tail->data == elem)
        {
            p = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete p;
            size--;
            return;
        }
        p = head->next;
        while (p->next != nullptr)
        {
            if (p->data == elem)
            {
                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete p;
                size--;
                return;
            }
            p = p->next;
        }
        cout << "Element not present in the list." << endl;
    }

    void search()
    {
        if (size == 0)
        {
            cout << "Empty list." << endl;
            return;
        }
        int elem;
        cout << "Enter the element to be searched: " << endl;
        cin >> elem;
        p = head;
        Node *q = tail;
        int beg = 1;
        int end = size;
        while (beg <= end)
        {
            if (p->data == elem)
            {
                cout << "Element found at " << beg << " node of the linked list." << endl;
                return;
            }
            if (q->data == elem)
            {
                cout << "Element found at " << end << " node of the linked list." << endl;
                return;
            }
            p = p->next;
            beg++;
            q = q->prev;
            end--;
        }
        cout << "Element not present in the lsit." << endl;
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
    int choice = 0;
    Doubly list;

    do
    {
        cout << "---------------------------" << endl;
        cout << "Menu." << endl;
        cout << "1.Insert an element in list." << endl;
        cout << "2. Display linked list." << endl;
        cout << "3.Insert at desired position." << endl;
        cout << "4.Delete an element." << endl;
        cout << "5.Search an element." << endl;
        cout << "6.Exit" << endl;
        cin >> choice;
        cout << "---------------------------" << endl;

        switch (choice)
        {
        case 1:
            list.getinput();
            break;

        case 2:
            list.display();
            break;

        case 3:
            int node_count;
            node_count = list.getcount();
            list.insert(node_count);
            break;

        case 4:
            list.remove();
            break;

        case 5:
            list.search();
            break;

        case 6:
            cout << "Exiting the code." << endl;
            break;

        default:
            cout << "Enter a valid choice from 1-6." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}