#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) // bruteforce O(NlogN)
{
    multiset<pair<int, int>> set1;
    int n = prices.size();
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        set1.insert({prices[i - 1], prices[i]});
    }
    for (auto set : set1)
    {
        cout << set.first << ", " << set.second << endl;
        if (set.first < set.second)
        {

            res = res + set.second - set.first;
            // cout << res << ", ";
        }
    }

    return res;
}

int Max_profit(vector<int> &prices) //O(n)
{
    int n = prices.size();
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            res = res + prices[i] - prices[i - 1];
        }
    }

    return res;
}

int main()
{
    vector<int> prices = {2, 1, 2, 1, 0, 1, 2};
    cout << maxProfit(prices) << endl;
    cout << Max_profit(prices) << endl;
}