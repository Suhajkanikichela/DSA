#include<iostream>
using namespace std;

template <class T>
class arithmetic
{
    private:     
    T a, b;

    public:

    arithmetic(T x, T y)
    {
        a=x;
        b=y;
    }
    
    T add()
    {
        return a+b;
    }

    T sub()
    {
        return a-b;
    }

    T mul()
    {
        return a*b;
    }

    T div()
    {
        return a/b;
    }
};

int main()
{

    float x, y;
    int choice = 0;
    
    cout<<"Enter the first number: "<<endl;
    cin>>x;
    cout<<"Enter the second number: "<<endl;
    cin>>y;

    arithmetic <float> ar(x,y);

     while (choice!=5)
    {
        cout<<"------------------"<<endl;
        cout<<"1. Addition."<<endl;
        cout<<"2. Subtraction."<<endl;
        cout<<"3. Multiplication."<<endl;
        cout<<"4. Division."<<endl;
        cout<<"5. Exit."<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<"Sum = "<<ar.add()<<endl;
            break;

            case 2:
            cout<<"Difference = "<<ar.sub()<<endl;
            break;

            case 3:
            cout<<"Product = "<<ar.mul()<<endl;
            break;

            case 4:
            cout<<"Division = "<<ar.div()<<endl;
            break;

            case 5:
            cout<<"Code exited."<<endl;
            break;

            default:
            cout<<"Enter a valid choice from 1 - 5."<<endl;
            break;
        }
    };

    return 0;
}