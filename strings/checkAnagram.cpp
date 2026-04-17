#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int max=100;
    char a[max];
    char b[max];

    cout<<"Only Enter Lowercase."<<endl;
    cout<<"Enter 1st string: "<<endl;
    cin.getline(a, max);

    cout<<"Enter 2nd string: "<<endl;
    cin.getline(b, max);

    int H[26]={0};

    for (int i = 0; a[i] != '\0'; i++)
    {
        H[a[i]-97] += 1; 
    }
    for (int i = 0; b[i] != '\0'; i++)
    {
        H[b[i]-97] -= 1;
    }
    for (int i =0; i<26; i++)
    {    
        if (H[i] != 0)
        {
            cout<<"Not Anagram."<<endl;
            return 0;
        }    
    } 
    cout<<"Anagram Detected."<<endl;

    return 0;
}