#include<iostream>
#include<string.h>
using namespace std;

class Permetuation
{
    private:
        int max = 10;
        char s[100]; // Fixed array declaration
        int count = 0;

    public:
        Permetuation()
        {
            cout << "Enter a string: " << endl;
            cin.getline(s, max);
        }

        void length()
        {
            count = strlen(s); // Simplified length calculation
            cout << "Length of the string is: " << count << endl;
        }

        int fac(int n)
        {
            if (n <= 1)
            {
                return 1;
            }
            return n * fac(n - 1);
        }

        void permute(char s[], int k)
        {
            static int arr[100] = {0}; // Made arr static and fixed its size
            static char result[100]; // Made result static and fixed its size

            if (s[k] == '\0')
            {
                result[k] = '\0';
                cout << result << endl;
            }
            else
            {
                for (int i = 0; s[i] != '\0'; i++)
                {
                    if (arr[i] == 0)
                    {
                        result[k] = s[i];
                        arr[i] = 1;
                        permute(s, k + 1);
                        arr[i] = 0;
                    }
                }
            }
        }

        void generatePermutations() // Added a new function to call permute
        {
            permute(s, 0);
        }

        int getCount() const // Added getter for count
        {
            return count;
        }
};

int main()
{
    Permetuation p;
    p.length();
    cout << "Factorial of the length is: " << p.fac(p.getCount()) << endl; // Use getCount() to access count
    p.generatePermutations(); // Call generatePermutations to print permutations

    return 0;
}