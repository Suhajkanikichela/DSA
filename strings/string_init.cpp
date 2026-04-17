#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int maxlength=100;
    char s[maxlength];

    cout<<"Enter input for string."<<endl;
    cin.getline(s, maxlength);

    cout<<s<<endl;

    return 0;
}