/*
find the first occurance of x, if not present find the the closest indics of x.

constrants:

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cin >> x;

    int ub = n - 1, lb = 0, closest_G = -1, closest_S = -1, ans = -1;
    while (ub >= lb)
    {
        int mid_idx = (lb + ub) / 2, mid_val = arr[mid_idx];
        if (mid_val > x)
        {
            ub = mid_idx - 1;
            closest_G = mid_idx;
        }
        else if (mid_val < x)
        {
            lb = mid_idx + 1;
            closest_S = mid_idx;
        }
        else
        {
            ans = mid_idx;
            ub = mid_idx - 1;
        }
    }

    if (ans == -1)
        cout << x << " Not found!"
             << "  closest indics: " << closest_S << " and " << closest_G << endl;
    else
        cout << x << " found! at " << ans << endl;
    return 0;
}