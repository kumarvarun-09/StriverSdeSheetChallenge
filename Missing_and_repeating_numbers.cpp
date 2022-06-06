#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &A, int n)
{
	// Write your code here 
    pair<int,int> ans;
	for(int i = 0; i < n; i++)
    {
        int t = abs(A[i]) - 1;
        if(A[t] < 0)
        {
            //this means that this block has already been visited
            ans.second = t + 1;
        }
        else
        {
            A[t] = -A[t];
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(A[i] > 0)
        {
            ans.first = i + 1;
            break;
        }
    }
    return ans;
}
