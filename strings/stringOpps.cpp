#include <iostream>
#include <cstring> // For strlen
using namespace std;

class StringOperations
{
public:
    // Function to validate a string
    int validate(const char *s)
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == ' '))
            {
                cout << "Invalid character: " << s[i] << endl;
                return 0; // Invalid string
            }
        }
        return 1; // Valid string
    }

    // Function to count the number of words in a string
    void countWords(char *s)
    {
        int i, word = 0;
        for (i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == ' ' && s[i - 1] != ' ')
            {
                word++;
            }
        }
        cout << "The number of words in the string = " << word + 1 << endl;
    }

    // Function to toggle the case of characters in a string
    void toggleCase(char *s)
    {
        int i;
        for (i = 0; s[i] != '\0'; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 32; // Convert to lowercase
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] -= 32; // Convert to uppercase
            }  
        }
        cout << "Toggled case string: " << s << endl;
    }

    // Function to count frequency of lowercase letters
    void countLetterFrequency(char *s)
    {
        int h[26] = {0}; // Array to count frequency of each letter

        // Count frequency of each lowercase letter
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                h[s[i] - 'a'] += 1;
            }
        }

        // Print letters that appear more than once
        for (int i = 0; i < 26; i++)
        {
            if (h[i] > 1)
            {
                cout << (char)(i + 'a') << "\t" << h[i] << endl;
            }
        }
    }
};

int main()
{
    StringOperations strOps;
    int choice;
    char input[100]; // Buffer for user input

    do
    {
        cout << endl;
        cout << "Menu: " << endl;
        cout << "1. Validate a string" << endl;
        cout << "2. Count the number of words in a string" << endl;
        cout << "3. Toggle the case of characters in a string" << endl;
        cout << "4. Count frequency of lowercase letters" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear the newline character from the input buffer

        switch (choice)
        {
        case 1:
            cout << "Enter a string to validate: ";
            cin.getline(input, 100);
            if (strOps.validate(input))
            {
                cout << "Valid String" << endl;
            }
            else
            {
                cout << "Invalid String" << endl;
            }
            break;

        case 2:
            cout << "Enter a string to count words: ";
            cin.getline(input, 100);
            strOps.countWords(input);
            break;

        case 3:
            cout << "Enter a string to toggle case: ";
            cin.getline(input, 100);
            strOps.toggleCase(input);
            break;

        case 4:
            cout << "Enter a string to count letter frequency: ";
            cin.getline(input, 100);
            strOps.countLetterFrequency(input);
            break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}