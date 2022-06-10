#include <bits/stdc++.h> 
unordered_map<int, pair<int, int>> allPairs(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, pair<int, int>> mp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            mp[sum] = {i, j};
        }
    }
    return mp;
}
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    unordered_map<int, pair<int, int>> mp = allPairs(arr);
   for(int i = 0; i < n - 1; i++)
   { 
       for(int j = i + 1; j < n; j++)
       {
           int to_find = target - arr[i] - arr[j];
           if(mp.find(to_find) != mp.end())
           {
                auto p = mp[to_find];
                if(p.first != i && p.first != j && p.second != i && p.second != j)
                {
                    return "Yes";
                }
           }
        }
    }
    return "No";
}
