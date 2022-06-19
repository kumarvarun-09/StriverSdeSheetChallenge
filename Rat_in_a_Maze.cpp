// CODESTUDIO PROBLEM CODE


void solve(int i, int j, int n, vector<vector<int>> &ans, vector<vector<int>> &m, vector<int> &visited)
{
    if(i == n - 1 && j == n - 1 && m[i][j])
    {
        visited[(i * n) + j] = 1;
        ans.push_back(visited);
        visited[(i * n) + j] = 0;
        return;
    }
    if(i < 0 || j < 0 || i >= n || j >= n)
    {
        return;
    }
    
    if(m[i][j] == 1 && visited[(i * n) + j] == 0)
    {
        visited[(i * n) + j] = 1;
        solve(i - 1, j, n, ans, m, visited);
        solve(i + 1, j, n, ans, m, visited);
        solve(i, j - 1, n, ans, m, visited);
        solve(i, j + 1, n, ans, m, visited);
        visited[(i * n) + j] = 0;
    }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int>> ans;
    vector<int> visited(n * n, 0);
    solve(0, 0, n, ans, maze, visited);
    return ans;
}




_________________________________________________________________________________________________________________________________________________________________________________________________
  
  
  
  
  
  
  
  //GFG PROBLEM CODE
  
  
  
  
  // { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(int i, int j, int n, string &ds, vector<string> & ans, vector<vector<int>> &m, vector<vector<int>> &visited)
    {
        if(i == n - 1 && j == n - 1 && m[i][j])
        {
            ans.push_back(ds);
            return;
        }
        if(i < 0 || j < 0 || i >= n || j >= n)
        return;
        
        if(m[i][j] == 1 && visited[i][j] == 0)
        {
            visited[i][j] = 1;
            ds.push_back('U');
            solve(i - 1, j, n, ds, ans, m, visited);
            ds[ds.length() - 1] = 'D';
            solve(i + 1, j, n, ds, ans, m, visited);
            ds[ds.length() - 1] = 'L';
            solve(i, j - 1, n, ds, ans, m, visited);
            ds[ds.length() - 1] = 'R';
            solve(i, j + 1, n, ds, ans, m, visited);
            ds.pop_back();
            visited[i][j] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string ds;
        vector<string> ans;
        vector<vector<int>> v(n, vector<int> (n, 0));
        solve(0, 0, n, ds, ans, m, v);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends




