#include<iostream>
using namespace std;

int x = 0; //Here it is global thats why the second time value increases
//if it was declared as static variable the value would remain same.

int fun(int n)
{
    if(n>0)
    {
         
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

int main()
{
    int num;
    cout<<"Enter any no. : "<<endl;
    cin>>num;

    cout<<fun(num)<<"\t";
    cout<<fun(num);

    return 0;
}