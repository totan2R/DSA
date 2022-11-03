#include <iostream>
using namespace std;
// https://leetcode.com/problems/find-pivot-index/

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int r_sum = 0;
    for (int i = 0; i < n; i++)
        r_sum += arr[i];

    int l_sum = 0;
    for (int i = 0; i < n; i++)
    {
        r_sum -= arr[i];
        if (l_sum == r_sum)
        {
            cout << i << endl;
            break;
        }
        l_sum += arr[i];
    }
    return 0;
}