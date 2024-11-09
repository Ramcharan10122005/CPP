#include <bits/stdc++.h>
using namespace std;
vector<int> FirstNegativeInteger(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> result;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            result.push_back(arr[i]);
        }   
    }
    
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
}