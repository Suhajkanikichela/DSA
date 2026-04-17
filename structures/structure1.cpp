#include<iostream>
using namespace std;

struct complex
{
    int real;
    int imaginary;
};

int main()
{
    int choice;
    complex c1, c2;
    cout<<"Enter the real part of first number: "<<endl;
    cin>>c1.real;
    cout<<"Enter the imaginary part of first number: "<<endl;
    cin>>c1.imaginary;
    cout<<"First complex number: "<<c1.real<<" (+i)"<<c1.imaginary<<endl;
    cout<<"-------------------"<<endl;
    cout<<"Enter the real part of second number: "<<endl;
    cin>>c2.real;
    cout<<"Enter the imaginary part of first number: "<<endl;
    cin>>c2.imaginary;
    cout<<"Second complex number: "<<c2.real<<" (+i)"<<c2.imaginary<<endl;

    do
    {
        cout<<"-------------------"<<endl;
        cout<<"Enter your choice: "<<endl;
        cout<<"1. Sum."<<endl;
        cout<<"2. Difference."<<endl;
        cout<<"3. Product. "<<endl;
        cout<<"4. Exit."<<endl; 
        cin>>choice;
        cout<<"-------------------"<<endl;

        switch(choice)
        {
            case 1:
            cout<<"Sum = "<<c1.real+c2.real<<" (+i)"<<c1.imaginary+c2.imaginary<<endl;
            break;

            case 2:
            cout<<"Difference = "<<c1.real-c2.real<<" (+i)"<<c1.imaginary-c2.imaginary<<endl;
            break;

            case 3:
            cout<<"Product = "<<((c1.real*c2.real)+(c1.imaginary*c2.imaginary))<<endl;
            break;

            case 4:
            cout<<"Exited the code."<<endl;
            break;

            default:
            cout<<"Enter a valid choice from 1-4."<<endl;


        }
    }while(choice != 4);


    return 0;
}