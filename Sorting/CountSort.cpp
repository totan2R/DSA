#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int A[n];

    // Input and finding maximum value
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];

        if (A[i] > max)
        {
            max = A[i];
        }
    }

    // fill new frequency array with 0,
    int freqA[max + 1] = {0};

    // count elements and store to the ith index
    for (int i = 0; i < n; i++)
    {
        freqA[A[i]]++;
    }

    // cumulative array
    for (int i = 1; i <= max; i++)
    {
        freqA[i] += freqA[i - 1];
    }

    int outputA[n];
    // Find the index of each element of the original array in frequency array, and
    // place the elements in output array
    for (int i = n - 1; i >= 0; i--) // backtraverse is requird for correctness
    {
        int indx = freqA[A[i]] - 1;
        outputA[indx] = A[i];
        freqA[A[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << outputA[i] << " ";
    }
    cout << endl;
}