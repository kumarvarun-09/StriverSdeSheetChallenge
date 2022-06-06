#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutations, int n)
{
    //  Write your code here.
    vector<int> p = permutations;
    
   int i;
    for(i = n - 2; i >= 0; i--)
    {
        if(p[i] < p[i + 1])
            break;
    }
    int j;
    if(i >= 0)
    for(j = n - 1; j > i; j--)
    {
        if(p[i] < p[j])
        {
            swap(p[i], p[j]);
            break;
        }
    }
    reverse(p.begin() + i + 1, p.end());
    return p;
}
