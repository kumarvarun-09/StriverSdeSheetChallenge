bool isPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while(i < j)
    {
        if(s[i++] != s[j--])
            return false;
    }
    return true;
}
void solve(int ind, string &s, vector<string> &ds, vector<vector<string>> &ans)
{
    int n = s.length();
    if(ind == n)
    {
        ans.push_back(ds);
        return;
    }
    
    for(int i = ind; i < n; i++)
    {
        string temp = s.substr(ind, i - ind + 1);
        if(isPalindrome(temp))
        {
            ds.push_back(temp);
            solve(i + 1, s, ds, ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<string> ds;
    vector<vector<string>> ans;
    solve(0, s, ds, ans);
    return ans;
}
