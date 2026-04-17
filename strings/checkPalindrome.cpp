#include<iostream>
#include<string.h>
using namespace std;

void palindrome(const char s[], const char reverseS[])
{
    int x, y;

    for(x=0, y=0; s[x] != '\0' && reverseS[y] != '\0'; x++, y++)
    {
        if (s[x] != reverseS[y])
        {
            cout<<"Not a Palindrome."<<endl;
            return;
        }
    }
    cout<<"Palindrome detected."<<endl;
}

int main()
{
    const int MAX_LENGTH = 100; // Define a maximum length for the input string
    char s[MAX_LENGTH];


    cout << "Enter a string: ";
    cin.getline(s, MAX_LENGTH);


    int i, j;

    for (i = 0; s[i] != '\0'; i++)
    {
    }
    cout<<"String Length is: "<<i<<endl;

    char reverseS[i+1];
    for (j = 0; j < i; j++)
    {
        reverseS[j] = s[i-j-1];
    }
    
    reverseS[i]='\0';

    cout<<"Reversed string is: "<<reverseS<<endl;

    palindrome(s, reverseS);

    return 0;
}