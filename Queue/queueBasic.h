#include <iostream>
using namespace std;

template <typename N>
class Node
{
public:
    N data;
    Node *next;
    Node(N data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename Q>
class Queue
{
    Node<Q> *front;
    Node<Q> *last;

public:
    Queue()
    {
        front = NULL;
        last = NULL;
    }

    // enqueue --> push(val)
    void push(Q val)
    {
        Node<Q> *newNode = new Node<Q>(val);

        if (front == NULL)
        {
            front = newNode;
            last = newNode;
            return;
        }
        last->next = newNode;
        last = last->next;
    }

    // deque --> pop
    Q pop()
    {
        Q chk;
        if (last == NULL)
        {
            cout << "Queue Underflow" << endl;
            return chk;
        }

        Node<Q> *delNode = front;
        chk = front->data;
        front = front->next;

        if (front == NULL)
        {
            last = NULL;
        }

        delete delNode;
        return chk;
    }

    // peek --- front() back()
    Q Front()
    {
        if(front == NULL)
        {
            return "queue underflow";
        }
        Q chk = front->data;
        return chk;
    }
    Q Back()
    {
        if(front == NULL)
        {
            return "queue underflow";
        }
        Q chk = last->data;
        return chk;
    }
    // empty -- empty()
    bool empty()
    {
        if (front == NULL && last == NULL)
        {
            return true;
        }
        else
            return false;
    }
};