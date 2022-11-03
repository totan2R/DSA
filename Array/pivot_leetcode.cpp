#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int r_sum = 0;
        for (int i = 0; i < nums.size(); i++)
            r_sum += nums[i];

        int l_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            r_sum -= nums[i];
            if (l_sum == r_sum)
            {
                return i;
            }
            l_sum += nums[i];
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v[i] = num;
    }

    // for (int k : v)
    //     cout << k << " ";
    // cout << endl;

    // for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    //     cout << *i << " ";
    // cout<<endl;

    Solution pivot;
    cout<<pivot.pivotIndex(v)<<endl;
}