#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int A[n];

    // Input and finding maximum value
    int fsize = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];

        if (A[i] > fsize)
        {
            fsize = A[i];
        }
    }

    // fill new frequency array with 0,
    int freqA[fsize + 1] = {0};

    // count elements and store to the ith index
    for (int i = 0; i < n; i++)
    {
        freqA[A[i]]++;
    }

    // Add counted sortd indexd value to the original array (simple count)
    int i = 0, j = 0; // frequency array index = j, orginal array index = i
    while (i <= fsize)
    {
        if (freqA[j] > 0)
        {
            A[i] = j;
            i++;
            freqA[j]--;
        }
        else
        {
            j++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}