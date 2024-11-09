// input: arr[] = {0, -1, 2, -3, 1} target = -2
// output: True
// here is a pair (1, -3) with the sum equal to given target, 1 + (-3) = -2

#include <bits/stdc++.h>
using namespace std;

bool twosum(vector<int> &arr, int target) // using hashset O(n)
{
    unordered_set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        int temp = target - arr[i];
        if (s.find(temp) != s.end())
        {
            cout << "Pair found: (" << temp << ", " << arr[i] << ")" << endl;
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}

bool twosum_twoPointer(vector<int> &arr, int target) // O(n*log(n))
{
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            cout << "Pair found: (" << arr[left] << ", " << arr[right] << ")" << endl;
            return true;
        }
        else if (sum < target)
        {
            left++;
        }
        else if (sum > target)
        {
            right--;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;
    bool result = twosum_twoPointer(arr, target);
    cout << "Result: " << (result ? "True" : "False") << endl;
    result = twosum(arr, target);
    cout << "Result: " << (result ? "True" : "False") << endl;
    return 0;
}