#include<iostream>
using namespace std;

int main()
{
    int m=0, n=0;
    cout<<"Enter no. of rows: "<<endl;
    cin>>m;
    cout<<"Enter no. of columns: "<<endl;
    cin>>n;
    int arr[m][n];

    cout<<"Input the values for matrix."<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }   
    }

    for (int i = 0; i < m; i++)
    {
        cout<<"[ ";
        for (int j = 0; j < n; j++)
        {
            cout<<" "<<arr[i][j];
        }   
        cout<<"]"<<endl;
    }    
    
    return 0;
}