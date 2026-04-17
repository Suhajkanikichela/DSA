#include<iostream>
using namespace std;

int F[10];

class fib
{
    private:
    int n;

    public:
    int mfib(int n) //Memorisation
    {
        if(n<=1)
        {
            F[n]=n;
            return n;
        }
        else
        {
            if(F[n-2]==-1)
            {
                F[n-2] = mfib(n-2);
            }
            if(F[n-1]==-1)
            {
                F[n-1] = mfib(n-1);
            }
            return F[n-2]+ F[n-1];
        }
    }

    int ifib(int n) //Iterative using loop;
    {
        int t0=0; int t1=1, s=0;
        
        if(n<=1)
        {
            return n;
        }

        for(int i=2; i<=n; i++)
        {
            s=t0+t1;
            t0=t1;
            t1=s;
        }
        return s;
    }

    int rfib(int n) //recursion
    {
        if(n == 0) 
        {
            return 0;
        }
        else if(n == 1)
        {
            return 1;
        }
        else
        {
            return rfib(n-2) + rfib(n-1);
        }
    }
};


int main()
{
    fib f;

    for(int i=0; i<10; i++)
    {
        F[i]=-1;
    }

    int x;

    cout<<"Enter the term: "<<endl;
    cin>>x;

    cout<<"Value = "<<f.mfib(x)<<endl; //Change m to i or r for loop or recursive respectively

    return 0;
}