#include<iostream>
using namespace std;

void fun(int n)
{
    if(n>0)
    {
        cout<<n<<"\t";
        fun(n-1);
        fun(n-2);

    }
}

int main()
{
    int x;
    cout<<"Enter any number: "<<endl;
    cin>>x;

    fun(x);
    return 0;
}