#include <iostream>
#include <utility>
#include "queueBasic.h"
using namespace std;

int main()
{
    Queue<int> q;
    q.push(1);
    q.push(2);

    Queue<string> q2;
    q2.push("totan");
    q2.push("toan");

    typedef pair<string, int> mytype;

    Queue<mytype> q3;
    q3.push(make_pair("totan", 177311));
    q3.push(make_pair("miton", 173311));
    q3.push(make_pair("ringku", 343422));

    while (!q3.empty())
    {
        cout << q3.pop().first <<" | "<<q3.pop().second<< endl;
    }
}