#include<iostream>
using namespace std;

/*
int factorial(int n) //recursive function for factorial
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}

int nCr(int n, int r) //mathematical expression
{
    int num, den;
    num=factorial(n);
    den=factorial(r)*factorial(n-r);

    return num/den;
}
*/

int r_ncr(int n, int r) //pascals triangle using recursion
{
    if( n==r || r ==0 )
    {
        return 1;
    }
    else
    {
        return r_ncr(n-1,r-1)+r_ncr(n-1,r);
    }
}

int main()
{
    int x,y;
    cout<<"Enter N for combination: "<<endl;
    cin>>x;
    cout<<"Enter R for combinaton: "<<endl;
    cin>>y;

    cout<<"Value = "<<r_ncr(x,y)<<endl;

    return 0;
}