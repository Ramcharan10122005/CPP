#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfSubarrays(vector<int> &arr, int k)
{
    vector<int> ans;
    int n = arr.size();
    int res = 0;
    for (int i = 0; i < k; i++)
    {
        res += arr[i];
    }
    ans.push_back(res);
    for (int i = k; i < n; i++)
    {
        res = (res - arr[i - k]) + arr[i];
        ans.push_back(res);
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 3;
    vector<int> result = maxOfSubarrays(arr, k);
    for (int res : result)
    {
        cout << res << ", ";
    }
    return 0;
}