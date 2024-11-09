#include <bits/stdc++.h>
using namespace std;

// count for distinct elements in an array.
//  int count(vector<int> &temp)
//  {
//      unordered_set<int> s;
//      int cnt = 0;
//      int n = temp.size();
//      for (int i = 0; i < n; i++)
//      {
//          if (s.find(temp[i]) == s.end())
//          {
//              s.insert(temp[i]);
//              cnt++;
//          }
//      }
//      return cnt;
//  }

vector<int> countDistinct(int k, vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> map;
    vector<int> result;
    for (int i = 0; i < k; i++) // count window size elements
    {
        map[arr[i]]++;
    }
    result.push_back(map.size());

    for (int i = 1; i <= n - k; i++)
    {
        map[arr[i - 1]]--; // removing because sliding out of the window
        if (map[arr[i - 1]] <= 0)
        {
            map.erase(arr[i - 1]);
        }

        map[arr[i + k - 1]]++; // adding new element in the window
        result.push_back(map.size());
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4; // window size
    vector<int> res = countDistinct(k, arr);
    for (auto r : res)
    {
        cout << r << ", ";
    }
    cout << endl;
}