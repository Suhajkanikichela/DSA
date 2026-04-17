#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class niceNum
{
private:
    int count;

public:
    niceNum() 
    { 
        count = 0; 
    }

    void pattern(int num)
    {
        if (num % 1111 == 0) 
        {
            cout << "The number " << num << " will always result in 0, leading to an infinite loop." << endl;
            return;
        }
        while (num != 6174)
        {
            vector<int> digits;

            digits.push_back(num / 1000);
            digits.push_back((num / 100) % 10);
            digits.push_back((num / 10) % 10);
            digits.push_back(num % 10);

            vector<int> asc = digits;
            sort(asc.begin(), asc.end());

            vector<int> desc = asc;
            reverse(desc.begin(), desc.end());

            int newNum1 = asc[0] * 1000 + asc[1] * 100 + asc[2] * 10 + asc[3];
            int newNum2 = desc[0] * 1000 + desc[1] * 100 + desc[2] * 10 + desc[3];

            num = newNum2 - newNum1;
            count++;

            cout << "Step " << count << ": " << newNum2 << " - " << newNum1 << " = " << num << endl;
        }
        cout << "Reached Kaprekar's constant in " << count << " steps.\n";
    }
};

int main()
{
    int num;
    cout << "Enter any 4-digit number of your choice: ";
    cin >> num;

    while (num < 1000 || num > 9999)
    {
        cout << "Invalid number entered. Enter a 4-digit number again: ";
        cin >> num;
    }

    niceNum obj;
    obj.pattern(num);

    return 0;
}
