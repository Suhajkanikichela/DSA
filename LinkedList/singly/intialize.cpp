#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * p;
    Node(){};
    Node(int d): data(d) , p(nullptr){};
    Node(int d , Node* point): data(d) , p(point){};
};

void printLinkedList(Node * &head){
    Node * temp = head;
    while(temp != nullptr){
        cout<<temp->data<<endl;
        temp=temp->p;
    };
}

int main()
{
    Node *head = new Node(5,new Node(6, new Node(7,new Node(8,nullptr))));
     printLinkedList(head);
    return 0;
}





// -------------------------------------------------------------------------------------------------------------
// CREATION OF LINKED LIST (AUTOMATED)
// Best approcach


// int main(){
//     const int n = 7;
//     Node* head;
//     Node * temp = head;
//             head = new Node(rand()%101);
//             temp= head->p;

//     for (int i = 0; i < n; i++)
//     {
//             temp->p = new Node(rand()%101);
//              temp= temp->next;
//     };
//     return 0;
// }



// attempt 1
// int main()
// {
//     Node * head  = new Node (5);
//     head->p = new Node(6);
//     head->p->p = new Node(7);
//     head->p->p->p = new Node(8);
//     return 0;
// }


// attempt 2
// int main()
// {
//     Node *head = new Node(5,
//      new Node(6, 
//      new Node(7,
//      new Node(8))));

//     return 0;
// }