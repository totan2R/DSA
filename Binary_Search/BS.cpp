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

    int ub = n - 1, lb = 0, ans = -1;
    while (ub >= lb)
    {
        int mid_idx = (lb + ub) / 2;
        int mid_val = arr[mid_idx];
        if (mid_val > x)
            ub = mid_idx - 1;
        else if (mid_val < x)
            lb = mid_idx + 1;
        else
        {
            ans = mid_idx;
            break;
        }
    }
    cout << x << " found! at " << ans << endl;
    return 0;
}