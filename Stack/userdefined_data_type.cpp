#include <iostream>
#include "stackBasic.h"
using namespace std;

// Generic implementation can be use any user and primitive data type
// Generic implementation using user-defined data type

int globalID = 100;

class person
{
    string name;
    int id;
    float salary; // doller

public:
    person()
    {
        name = "";
        id = -1;
        salary = -1.0;
    }
    // setter
    void setName(string name)
    {
        this->name = name;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }
    person(string name, float salary)
    {
        setName(name);
        setSalary(salary);
        id = globalID;
        globalID++;
    }

    // getter
    int gitID()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    float getSalary()
    {
        return salary;
    }
    void print()
    {
        cout << name << " | " << id << " | " << salary << endl;
    }
};

int main()
{
    Stack<person> stk;
    person a("Totan Sarker", 10000.8);
    person b("Miton Sarker", 8000.8);
    person c("Ringku Sarker", 300.8);
    person d("Jibon Sarker", 335.8);
    person e("Jhorna Sarker", 44.8);

    stk.push(a);
    stk.push(b);
    stk.push(c);
    stk.push(d);
    stk.push(e);

    while (!stk.empty())
    {
        person printobj;
        printobj = stk.pop();

        printobj.print();
    }
    stk.Top();
}