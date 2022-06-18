void solve(int ind, int n, string &s, vector<string> &ans)
{
    if(ind == n)
    {
        ans.push_back(s);
        return;
    }
    
    for(int i = ind; i < n; i++)
    {
        swap(s[ind], s[i]);
        solve(ind + 1, n, s, ans);
        swap(s[ind], s[i]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    solve(0, s.length(), s, ans);
    return ans;
}
