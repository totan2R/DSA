#include <iostream>
#include "stackBasic.h"
using namespace std;

int main()
{
    Stack <string>stk;

    stk.push("Totan");
    stk.push("Miton");
    stk.push("Ringku");
    stk.push("Maa");

    cout<<"size: "<<stk.size()<<endl;
    cout<<"top: "<<stk.Top()<<endl;

    while (!stk.empty())
    {
        cout<<stk.pop()<<endl;
        cout<<"top: "<<stk.Top()<<endl;
    }
}