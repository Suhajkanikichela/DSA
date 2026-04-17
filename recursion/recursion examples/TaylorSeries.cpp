#include<iostream>
using namespace std;

double e(int x, int n)
{
    static double s;

    if(n==0)
    {
        return s;
    }
    s = 1+x*s/n;
    return e(x,n-1);
}

int main()
{
    int n,t;
    cout<<"What should be the exponent: "<<endl;
    cin>>n;
    cout<<"For how many terms: "<<endl;
    cin>>t;

    cout<<"Taylor series: "<<e(n,t)<<endl;

    return 0;
}