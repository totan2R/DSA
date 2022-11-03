#include<iostream>
using namespace std;

int main()
{
    int base, argument, exponent = 0;
    //cin>>base>>argument;
    base = 2;
    argument = 16;

    while (argument!= 1)
    {
        argument/= base;// 16, 8, 4, 2 = 4times
        exponent++; 
    }
    cout<<exponent<<endl;
}