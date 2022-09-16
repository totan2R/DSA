#include <iostream>
#include "stackBasic.h"
using namespace std;

int main()
{
    Stack stk;

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);

    cout<<"size: "<<stk.size()<<endl;
    cout<<"top: "<<stk.Top()<<endl;

    while (!stk.empty())
    {
        cout<<stk.pop()<<endl;
        cout<<"top: "<<stk.Top()<<endl;
    }
}