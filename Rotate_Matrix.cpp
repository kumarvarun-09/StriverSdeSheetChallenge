#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int r1 = 0, r2 = n - 1;
    int c1 = 0, c2 = m - 1;
    while(r1 < r2 && c1 < c2)
    {
        for(int i = r1 + 1; i < r2; i++)
        {
            swap(mat[i][c1], mat[i + 1][c1]);
        }
        for(int i = c1; i < c2; i++)
        {
            swap(mat[r2][i], mat[r2][i + 1]);
        }
        for(int i = r2; i > r1; i--)
        {
            swap(mat[i][c2], mat[i - 1][c2]);
        }
        for(int i = c2; i > c1; i--)
        {
            swap(mat[r1][i], mat[r1][i - 1]);
        }
        r1++, c1++, r2--, c2--;
    }
}
