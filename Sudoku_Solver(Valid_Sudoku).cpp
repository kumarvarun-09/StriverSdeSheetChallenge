// CODESTUDIO PROBLEM CODE




bool isValid(int row, int col, int num, int matrix[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        if(matrix[row][i] == num || matrix[i][col] == num)
        {
            return false;
        }
    }
    int rowmod = row - (row % 3), colmod = col - (col % 3);
    for(int i = rowmod; i < rowmod + 3; i++)
    {
        for(int j = colmod; j < colmod + 3; j++)
        {
            if(matrix[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool solve(int matrix[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(matrix[i][j] == 0)
            {
                for(int num = 1; num <= 9; num++)
                {
                    if(isValid(i, j, num, matrix))
                    {
                        matrix[i][j] = num;
                        if(solve(matrix))
                        {
                            return true;
                        }
                        matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solve(matrix);
}




_____________________________________________________________________________________________________________________________________________________________________________________________________________
  
  
  
  
  
  // LEETCODE PROBLEM CODE
  
  
  
  
  
  class Solution {
public:
    
    bool isValid(int row, int col, char ch, vector<vector<char>> &board)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[row][i] == ch || board[i][col] == ch)
            {
                return false;
            }
        }
        
        int rowmod = row - (row % 3), colmod = col - (col % 3);
        for(int i = rowmod; i < rowmod + 3; i++)
        {
            for(int j = colmod; j < colmod + 3; j++)
            {
                if(board[i][j] == ch)
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board)
    {
          for(int i = 0; i < 9; i++)
          {
              for(int j = 0; j < 9; j++)
              {
                  if(board[i][j] == '.')
                  {
                      for(char ch = '1'; ch <= '9'; ch++)
                      {
                          if(isValid(i, j, ch, board))
                          {
                              board[i][j] = ch;
                              if(solve(board))
                              {
                                  return true;
                              }
                              board[i][j] = '.';
                          }
                      }
                      return false;
                  }
              }
          }
          return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

