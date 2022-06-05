#include<bits/stdc++.h>
void subset(vector<int> &v, vector<int> &ds, set<vector<int>> & ans, int i)
{
    int n = v.size();
    if(i == n)
    {
        ans.insert(ds);
        return;
    }
    subset(v, ds, ans, i + 1);
    ds.push_back(v[i]);
     subset(v, ds, ans, i + 1);
    ds.pop_back();
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<int> ds;
    set<vector<int>> temp;
    subset(arr, ds, temp, 0);
    vector<vector<int>> ans;
    for(auto x: temp)
    {
        ans.push_back(x);
    }
    return ans;
}
