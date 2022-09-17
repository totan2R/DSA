#include <iostream>
using namespace std;

// Stack using Function Template
// Function templates are special functions that can operate with generic types

template <typename N>
class DNode
{
public:
    N data;
    DNode *prev;
    DNode *next;

    DNode(N data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

template <typename S>
class Stack
{
    DNode<S> *head;
    DNode<S> *top; // tail of head
    int count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }
    // PUSH
    void push(S data)
    {
        DNode<S> *newNode = new DNode<S>(data);
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
    S pop()
    {
        DNode<S> *delnode;
        delnode = top;
        S chk = top->data;

        if (head == NULL)
        {
            cout << "Stack Underflow" << endl;
            return chk;
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
    S Top()
    {
        S chk;
        if (top == NULL)
        {
            cout << "Stack Underflow, there is no element" << endl;
        }
        else
            return top->data;
        return chk;
    }
};