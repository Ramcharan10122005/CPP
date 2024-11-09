#include <bits/stdc++.h>
using namespace std;

int maximumSubArray(vector<int> &arr, int k)
{
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int curr_sum = 0;
    for (int i = k; i < n; i++)
    {
        curr_sum += arr[i] - arr[i - k];
        sum = max(sum, curr_sum);
    }
    return sum;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 2; // subarraysize
    int res = maximumSubArray(arr, k);
    cout << res << endl;
}