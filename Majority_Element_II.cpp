#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &nums)
{
    // Write your code here.
        int n = nums.size() / 3;
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto x: nums)
        {
            mp[x]++;
        }
        for(auto x: mp)
        {
            if(x.second > n)
                ans.push_back(x.first);
        }
        sort(ans.begin(), ans. end());
        return ans;
}
