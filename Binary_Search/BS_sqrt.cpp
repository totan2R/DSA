#include <iostream>
using namespace std;

/*
Given a value X
Find sqrt(x) without math related libraries

constraints
1 <= X <= 2*10^19
*/
// 1073741823×1073741823
//  leetcode
class Solution
{
public:
    long long mySqrt(int n)
    {
        int ub = n, lb = 0;
        long long mid = (lb + ub) / 2;
        int ans = -1;

        while (ub >= lb)
        {
            long long squre = mid * mid;
            if (squre == n)
                return mid;
            if (squre < n)
            {
                ans = mid;
                lb = mid + 1;
            }
            else
                ub = mid - 1;
            mid = (lb + ub) / 2;
        }
        return ans;
    }
};

int main()
{
    // int x;
    // while (cin >> x && x > 0)
    // {
    //     double lb = 0, ub = x, ans = -1;
    //     while (ub - lb >= 0.00000001)
    //     {
    //         double mid = (lb + ub) / 2;
    //         double sqMid = mid * mid;

    //         if (sqMid > x)
    //             ub = mid;
    //         else
    //             lb = mid;
    //     }
    //     printf("%d -> %lf\n", x, lb);
    // }
    Solution s;
    int x;
    cin >> x;
    cout << s.mySqrt(x) << endl;
}