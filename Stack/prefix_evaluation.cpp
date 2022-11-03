#include <iostream>
#include <math.h>
#include "stackBasic.h"
using namespace std;

int prefixEvaluation(string chk)
{
    Stack<int> st;

    for (int i = chk.length() - 1; i >= 0; i--)
    {
        if (chk[i] >= '0' && chk[i] <= '9')
        {
            st.push(chk[i] - '0');
        }
        else
        {
            int a = st.pop();
            int b = st.pop();

            switch (chk[i])
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            case '^':
                st.push(pow(a, b));
                break;

            default:
                break;
            }
        }
    }
    return st.Top();
}

int main()
{

    cout << prefixEvaluation("+*423") << endl;//(4*2)+3 = infix
    cout << prefixEvaluation("-+7*45+20") << endl;//(7+(4*5)-(2+0)) = infix
    cout << prefixEvaluation("+*123") << endl;//(4*2)+3 = infix

    //cout << prefixEvaluation("*+AB+CD") << endl;
    cout << prefixEvaluation("+9*3/84") << endl;
    
}