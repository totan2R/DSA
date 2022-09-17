#include <iostream>
#include "stackBasic.h"
using namespace std;

// push words from a valid sentence.

int main()
{
    Stack<string> stk;
    string s = "I am Totan";
    string temp = "";
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            temp += s[i];
        }

        else
        {
            stk.push(temp);
            temp = "";
        }
    }
    stk.push(temp);

    while (!stk.empty())
    {
        cout << stk.pop() << endl;
    }
}