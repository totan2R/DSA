#include <iostream>
using namespace std;

class DNode
{
public:
    int data;
    DNode *prev;
    DNode *next;

    DNode(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class Stack
{
    DNode *head;
    DNode *top; // tail of head
    int count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }
    // PUSH
    void push(int data)
    {
        DNode *newNode = new DNode(data);
        if (head == NULL)
        {
            head = top = newNode;
            count++;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = newNode; // tail of head
        count++;
    }
    // POP
    int pop()
    {
        DNode *delnode;
        delnode = top;
        int chk = top->data;

        if (head == NULL)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        else if (top == head)
        {
            head = top = NULL;
            count--;
            return chk;
        }

        top = top->prev;
        top->next = NULL;

        delete delnode;
        count--;
        return chk;
    }
    // EMPTY
    bool empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    // SIZE
    int size()
    {
        return count;
    }
    // TOP
    int Top()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow, there is no element" << endl;
        }
        else
            return top->data;
        return -1;
    }
};