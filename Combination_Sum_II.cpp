#include<algorithm>
void solve(int i, int n, int sum, int trgt, vector<int> &v, vector<int> &ds, vector<vector<int>> &ans)
{
    if(sum == trgt)
        ans.push_back(ds);
    
    if(i == n || sum >= trgt)
        return;
    
    for(int j = i; j < n; j++)
    {
        if(j > i && v[j] == v[j - 1])
            continue;
        
        ds.push_back(v[j]);
        solve(j + 1, n, sum + v[j], trgt, v, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    sort(arr.begin(), arr.end());
    vector<int> ds;
    vector<vector<int>> temp;
    solve(0, n, 0, target, arr, ds, temp);
    return temp;
}
