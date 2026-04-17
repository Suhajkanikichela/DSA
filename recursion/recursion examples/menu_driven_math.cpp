#include<iostream>
using namespace std;

class math
{
    private:
    int n;
    int m;
   
    public:

    int sum(int n)
    {
        if(n==0)
        {
            return 0;
        }else
        {
            return sum(n-1)+n;
        }
    }

    int fac(int n)
    { 
        if(n<=1)
            {
                return 1;
            }else
            {
                return (n*fac(n-1));
            }
    }

    int exp(int m, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n%2 == 0)
        {
            return exp(m *m, n/2);
        }else 
        {
            return m* exp(m*m, (n-1)/2);
        }
    }
};


int main()
{
    math m;
    int choice;
    int a,b,c,d;
    do
    {
        cout<<"------------------------------"<<endl;
        cout<<"1. Sum upto n natural numbers."<<endl;
        cout<<"2. Factorial."<<endl;
        cout<<"3. Exponent."<<endl;
        cout<<"4. Exit."<<endl;
        cout<<"------------------------------"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<"Enter the number: "<<endl;
            cin>>a;
            cout<<"Sum upto n = "<<m.sum(a)<<endl;
            break;

            case 2:
            cout<<"Enter the number: "<<endl;
            cin>>b;
            cout<<"Factorial = "<<m.fac(b)<<endl;
            break;

            case 3:
            cout<<"Enter the base number: "<<endl;
            cin>>c;
            cout<<"Enter the exponent: "<<endl;
            cin>>d;
            cout<<"Result = "<<m.exp(c,d)<<endl;
            break;

            case 4:
            cout<<"Code exited."<<endl;
            break;

            default:
            cout<<"Enter a valid choice."<<endl;
            break;
        }

    }while(choice != 4);

    return 0;
}