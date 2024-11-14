#include <bits/stdc++.h>
using namespace std;

vector<int> FirstNegativeInteger(vector<int> &arr, int k)
{
    deque<int> Di;
    vector<int> ans;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        while (!Di.empty() && Di.front() < i - k + 1)
        {
            Di.pop_front();
        }

        if (arr[i] < 0)
        {
            Di.push_back(i);
        }

        if (i >= k - 1)
        {
            if (!Di.empty())
            {
                ans.push_back(arr[Di.front()]);
            }
            else
            {
                ans.push_back(0);
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;
    vector<int> result = FirstNegativeInteger(arr, k);

    for (int r : result)
    {
        cout << r << " ";
    }
    return 0;
}
