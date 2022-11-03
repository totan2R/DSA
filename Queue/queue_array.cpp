#include <iostream>
using namespace std;

class queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    queue()
    {
        size = 5;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // isEmpty()
    bool isEmpty()
    {
        if (front == size)
            return true;
        return false;
    }
    // inqueue
    void inqueue(int data)
    {
        if (rear == size)
        {
            cout << "queue is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }
    // dequeue
    int dequeue()
    {
        int popval;
        if (front == rear)
        {
            return -1;
        }
        else
        {
            popval = arr[front];
            arr[front] = -1;
            front++;
            return popval;
        }
    }
    // front
    int Front()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

int main()
{
    queue q;

    q.inqueue(23);
    q.inqueue(4);
    q.inqueue(6);
    q.inqueue(4);
    q.inqueue(33);
    q.inqueue(3);

    while (!q.isEmpty())
    {
        cout << q.Front() << endl;
        q.dequeue();
    }
}