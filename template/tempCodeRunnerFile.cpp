#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
    string mainStr, patternStr, replaceStr;

    cout << "Enter the main string (STR): ";
    cin >> mainStr;
    cout << "Enter the pattern string (PAT): ";
    cin >> patternStr;
    cout << "Enter the replacement string (REP): ";
    cin >> replaceStr;

    int pos=0;
    while (true) {
    pos = mainStr.find(patternStr, pos);
    if (pos == -1) break;

    mainStr.replace(pos, patternStr.length(), replaceStr);
    pos += replaceStr.length();
    }

    cout << "Resulting string: " << mainStr << endl;

    return 0;
}