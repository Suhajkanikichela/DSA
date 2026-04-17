#include<iostream>
using namespace std;

struct rectangle
{
    int length;
    int width;
};

int main()
{
    struct rectangle *p; //Declare pointer to rectangle
    p=new rectangle; //Dynamically allocates memory

    cout<<"Enter Length: "<<endl;
    cin>> p->length;
    cout<<"Enter Width: "<<endl;
    cin>> p->width;

    cout<<"----------------"<<endl;
    cout<< p->length <<endl;
    cout<< p->width <<endl;
    delete p; //Free the allocated memory

    return 0;
}