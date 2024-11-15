#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threesum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0)
            {
                result.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1])
                    l++;
                while (l < r && nums[r] == nums[r - 1])
                    r--;
                l++;
                r--;
            }
            else if (sum < 0)
                l++;
            else
                r--;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threesum(nums);
    cout << result.size() << endl;
    for (auto res : result)
    {
        for (auto r : res)
        {
            cout << r << " ";
        }
        cout << endl;
    }
}
