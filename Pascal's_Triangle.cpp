#include <bits/stdc++.h> 
void psum(vector<long long> &org, vector<long long> &des)
{
    int n = org.size();
    for(int i = 1; i < n; i++)
    {
        des.push_back(org[i] + org[i - 1]);
    }
}
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    n--;
    vector<vector<long long>> ans(n + 1);
    ans[0].push_back(1);
    for(int i = 1; i <= n; i++)
    {
        ans[i].push_back(1);
        psum(ans[i - 1], ans[i]);
        ans[i].push_back(1); 
    }
    return ans;
}
