#include <bits/stdc++.h> 
int mxprofit(vector<int> &p, int j, const int k)
{
    if(j >= k)
        return 0;
    int mxind = j, mnind = j;
    for(int i = j + 1; i <= k; i++)
    {
        if(p[i] > p[mxind])
            mxind  = i;
    }
    for(int i = j + 1; i < mxind; i++)   
    {
        if(p[i] < p[mnind])
            mnind  = i;
    }
    int ans = p[mxind] - p[mnind];
    return max(ans, mxprofit(p, mxind + 1, k));
}
int maximumProfit(vector<int> &prices){
    // Write your code here.
   return mxprofit(prices, 0, prices.size() - 1);
  
}
