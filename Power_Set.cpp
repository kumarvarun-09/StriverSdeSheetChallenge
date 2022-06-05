void pwset(vector<int> &v, vector<int> &ds, vector<vector<int>> & ans, int i)
{
    int n = v.size();
    if(i == n)
    {
        ans.push_back(ds);
        return;
    }
    pwset(v, ds, ans, i + 1);
    ds.push_back(v[i]);
     pwset(v, ds, ans, i + 1);
    ds.pop_back();
}
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<int> ds;
    vector<vector<int>> ans;
    pwset(v, ds, ans, 0);
    return ans;
}
