#include<bits/stdc++.h>
void solve(int i, int n, int sum, int k, vector<int> &v, vector<int> &ds, vector<vector<int>> &ans)
{
    if(i == n)
    {
        if(sum == k)
        {
            ans.push_back(ds);
        }
        return;
    }
    solve(i + 1, n, sum, k, v, ds, ans);
    ds.push_back(v[i]);
    solve(i + 1, n, sum + v[i], k, v, ds, ans);
    ds.pop_back();
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    vector<int> ds;
    vector<vector<int>> ans;
    solve(0, n, 0, k, arr, ds, ans);
 
    return ans;
}
