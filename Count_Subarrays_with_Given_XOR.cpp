#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    unordered_map<int, int> mp;
    int prevXOR = 0, cnt = 0;
    for (auto num : arr)
    {
        prevXOR ^= num;
        if (prevXOR == x)
            cnt++;

        if (mp.find(prevXOR ^ x) != mp.end())
        {
            cnt += mp[prevXOR ^ x];
        }

        // do not write this line anywhere above because it may increase the number of repeated counts
        mp[prevXOR]++;
    }
    return cnt;
}
