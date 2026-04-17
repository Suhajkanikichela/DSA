#include<iostream>
using namespace std;

void fun(int n)
{
    if(n>0)
    {
        cout<<n<<"\t";
        fun(n-1); //Tail recursion, while loop is better than it
    }
}

int main()
{
    int x;
    cout<<"Enter the number: "<<endl;
    cin>>x;

    fun(x);
    return 0;
}