#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

class Linked
{
private:
    Node *head, *tail;
    int length;

public:
    Linked(int val)
    {
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void getHead()
    {
        if (!head)
        {
            cout << "Empty List, No Head." << endl;
            return;
        }
        cout << "Head : " << head->val << endl;
    }

    void getTail()
    {
        if (!tail)
        {
            cout << "Empty List, No Tail." << endl;
            return;
        }
        cout << "Tail : " << tail->val << endl;
    }

    void getLength()
    {
        cout << "Length : " << length << endl;
    }

    void append(int val)
    {
        Node *newNode = new Node(val);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast()
    {
        if (length == 0)
        {
            cout << "Empty List, can't delete element." << endl;
            return;
        }
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *pre = head;
            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int val)
    {
        Node *newNode = new Node(val);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteFirst()
    {
        if (length == 0)
        {
            cout << "Empty List, can't delete first element." << endl;
            return;
        }
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        length--;
    }

    Node *get(int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Invalid Index provided." << endl;
            return nullptr;
        }
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    bool set(int val, int index)
    {
        Node *temp = get(index);
        if (temp)
        {
            temp->val = val;
            return true;
        }
        return false;
    }

    bool insert(int index, int val)
    {
        if (index < 0 || index > length)
        {
            cout << "Invalid Index provided." << endl;
            return false;
        }
        if (index == 0)
        {
            prepend(val);
            return true;
        }
        if (index == length)
        {
            append(val);
            return true;
        }

        Node *newNode = new Node(val);
        Node *temp = get(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void deleteNode(int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Invalid Index provided." << endl;
            return;
        }
        if (index == 0)
        {
            deleteFirst();
            return;
        }
        if (index == length - 1)
        {
            deleteLast();
            return;
        }

        Node *prev = get(index - 1);
        Node *temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse()
    {
        Node *temp = head;
        head = tail;
        tail = temp;
        Node *before = nullptr;
        Node *after = nullptr;
        for (int i = 0; i < length; i++)
        {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }

    ~Linked()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};

int main()
{
    Linked list(10);
    list.append(20);
    list.append(30);
    list.prepend(5);
    list.insert(2, 15); // List: 5 -> 10 -> 15 -> 20 -> 30

    cout << "List contents:\n";
    list.display();

    list.getHead();
    list.getTail();
    list.getLength();

    cout << "\nAfter deleting first element:\n";
    list.deleteFirst();
    list.display();

    cout << "\nAfter deleting last element:\n";
    list.deleteLast();
    list.display();

    cout << "\nAfter setting index 1 to 99:\n";
    list.set(99, 1);
    list.display();

    cout << "\nAfter reversing:\n";
    list.reverse();
    list.display();

    cout << "\nDeleting node at index 1:\n";
    list.deleteNode(1);
    list.display();

    cout << "\nFinal state of the list:\n";
    list.display();

    return 0;
}
