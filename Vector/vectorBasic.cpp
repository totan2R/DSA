#include <iostream>
using namespace std;

template <typename T>
class vectorClass
{
    T *arr;
    int capacity;
    int size;

public:
    vectorClass() // constructor function call when a object is create
    {
        arr = new T[1];
        capacity = 1;
        size = 0;
    }
    vectorClass(int size, T fill)
    {
        arr = new T[1];
        capacity = size;
        this->size = size;

        for (int i = 0; i < size; i++)
            arr[i] = fill;
    }
    vectorClass(vectorClass<T> *&v)
    {
        arr = new T[v->Size()];
        capacity = v->Size();
        size = v->Size();

        for(int i = 0; i<v->size; i++)
            arr[i] = v->get(i);
    }
    //~(tilt symbol)
    ~vectorClass() // destructor function call when a object destruct or program is terminated
    {
        delete[] arr;
    }

    void push_bk(T data)
    {
        if (size == capacity)
        {
            T *temp = new T[2 * capacity];

            for (int i = 0; i < capacity; i++)
                temp[i] = arr[i];

            delete[] arr;
            capacity *= 2;
            arr = temp;
        }

        arr[size] = data; // size-1 acting as index
        size++;           // this is actual
    }

    void push_indx(T data, int index)
    {
        if (index == capacity)
            push_bk(data);
        else
            arr[index] = data;
    }

    T get(int index)
    {
        if (index < size)
            return arr[index];
        return arr[0];
    }

    void pop_bk()
    {
        size--;
    }

    int Size()
    {
        return size;
    }

    int getcapacity()
    {
        return capacity;
    }
};

int main()
{
    vectorClass<int> v;
    vectorClass<int> v2(5, 0);
    vectorClass<char> c(7, 'c');
    vectorClass<int> a(v);

    v.push_bk(2);
    v.push_bk(4);
    v.push_indx(23, 1);
    v.push_bk(7);
    v.pop_bk();

    for (int i = 0; i < v.Size(); i++)
        cout << v.get(i) << " ";
    cout << endl;

    for (int i = 0; i < v2.Size(); i++)
        cout << v2.get(i) << " ";
    cout << endl;


    // for (int i = 0; i < a.Size(); i++)
    //     cout << a.get(i) << " ";
    // cout << endl;

    cout<<a.Size()<<endl;

    cout << typeid(v2).name() << endl;

    return 0;
}