#include <iostream>
#include "../stackBasic.h"
using namespace std;

// Reference: https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
/*
Write a program to check for balanced brackets in an expression.. Balanced brackets are the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in the given expression.

For example: [()]{}{[()()]()} is a balanced bracket.
              [({}]) is not a balanced bracket

You will be given a string, you need to check if the brackets are balanced or not. If they are balanced, print “YES”, otherwise print “NO”.

Expected time complexity: O(N)

Sample Input
({(())[{}])
({(())[{}]})

Sample output
NO
YES

*/

bool balanceParenthesis(string str)
{
    Stack<char> stk;

    int n = str.size();
    bool isBanlanced = true;

    if (str[0] == ')' || str[0] == '}' || str[0] == ']')
        return false;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stk.push(str[i]);
        }
        
        else if (str[i] == ')')
        {
            if (stk.Top() == '(')
                stk.pop();
            else
            {
                isBanlanced = false;
                break;
            }
        }
        
        else if (str[i] == '}')
        {
            if (stk.Top() == '{')
                stk.pop();
            else
            {
                isBanlanced = false;
                break;
            }
        }
        else if (str[i] == ']')
        {
            if (stk.Top() == '[')
                stk.pop();
            else
            {
                isBanlanced = false;
                break;
            }
        }
    }
    if(!stk.empty())
        return false;
    return isBanlanced;
}

int main()
{
    string chk;
    cin >> chk;
    if (balanceParenthesis(chk))
    {
        cout << "Balanced!" << endl;
        return 0;
    }
    cout << "Unbalanced!" << endl;
}