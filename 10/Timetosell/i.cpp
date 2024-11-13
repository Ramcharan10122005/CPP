#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) // O(n^2)
{

    // can be done simply:
    /*for (i = 0 to i < n-1)
    {
        for (int j = i + 1 to j < n)
        {
            res = max(res, prices[j] - prices[i])

                return res;
        }
*/
    int res = 0, x = 0, y = 0;
    set<pair<int, int>> set1;
    int n = prices.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pair p1 = make_pair(prices[i], prices[j]);
            set1.insert(p1);
        }
    }
    for (auto set : set1)
    {
        int diff = set.second - set.first;
        if (diff > res)
        {
            res = diff;
            x = set.first;
            y = set.second;
        }
    }
    cout << "(x, y): " << "( " << x << ", " << y << ")" << endl;
    return res;
}

int max_Profit(vector<int> &prices) // O(n)
{
    int n = prices.size();
    int minimum = prices[0];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (prices[i] < minimum)
        {
            minimum = prices[i];
        }
        int diff = prices[i] - minimum;
        if (diff > res)
        {
            res = diff;
        }
    }
    return res;
}

int main()
{
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    int res = maxProfit(prices);
    cout << "maxProfit: " << res << endl;
    res = max_Profit(prices);
    cout << "max_Profit: " << res << endl;
    return 0;
}