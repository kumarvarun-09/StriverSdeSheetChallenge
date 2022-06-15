void solve(int i, int n, int sum, vector<int> &v, vector<int>&ans)
{
    if(i == n)
    {
        ans.push_back(sum);
        return;
    }
    solve(i + 1, n, sum, v, ans);
    solve(i + 1, n, sum + v[i], v, ans);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    solve(0, num.size(), 0, num, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
