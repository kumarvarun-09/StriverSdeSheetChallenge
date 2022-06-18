//CODESTUDIO QUESTION CODE

void solve(int col, int n, vector<int> &ds, vector<vector<int>> &ans, vector<bool> &leftrow, vector<bool> &lowerdiagonal, vector<bool> &upperdiagonal)
    {
        if(col == n)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(!leftrow[row] && !lowerdiagonal[row + col] && !upperdiagonal[(n - 1) - row + col])
            {
                leftrow[row] = lowerdiagonal[row + col] = upperdiagonal[(n - 1) - row + col] = true;
                ds[n * row + col] = 1;
                
                solve(col + 1, n, ds, ans, leftrow, lowerdiagonal, upperdiagonal);
                
                leftrow[row] = lowerdiagonal[row + col] = upperdiagonal[(n - 1) - row + col] = false;
                ds[n * row + col] = 0;
            }
        }
    }
    
 vector<vector<int>> solveNQueens(int n) 
 {
        vector<int> ds(n * n, 0);
        vector<vector<int>> ans;
        vector<bool> rowleft(n, false), lowerdiagonal((2 * n) - 1, false), upperdiagonal((2 * n) - 1, false);
        solve(0, n, ds, ans, rowleft, lowerdiagonal, upperdiagonal);
        return ans;
    }



____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
  
  
  
  // LEETCODE QUESTION CODE
  
 
  
 class Solution {
public:
    
    void solve(int col, int n, vector<string> &ds, vector<vector<string>> &ans, vector<bool> &leftrow, vector<bool> &lowerdiagonal, vector<bool> &upperdiagonal)
    {
        if(col == n)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(!leftrow[row] && !lowerdiagonal[row + col] && !upperdiagonal[(n - 1) - row + col])
            {
                leftrow[row] = lowerdiagonal[row + col] = upperdiagonal[(n - 1) - row + col] = true;
                ds[row][col] = 'Q';
                
                solve(col + 1, n, ds, ans, leftrow, lowerdiagonal, upperdiagonal);
                
                leftrow[row] = lowerdiagonal[row + col] = upperdiagonal[(n - 1) - row + col] = false;
                ds[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ds(n, string(n, '.'));
        vector<vector<string>> ans;
        vector<bool> rowleft(n, false), lowerdiagonal((2 * n) - 1, false), upperdiagonal((2 * n) - 1, false);
        solve(0, n, ds, ans, rowleft, lowerdiagonal, upperdiagonal);
        return ans;
    }
};
