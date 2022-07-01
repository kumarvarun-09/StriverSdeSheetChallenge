#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
        // Write your code here.
        unordered_map<int, int> mp;
        for(auto x: nums)
        {
            mp[x]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto x: mp)
        {
            pq.push({x.second, x.first});
        }
        vector<int> ans;
        for(int i = 1; i <= k; i++)
        {
            ans.push_back((pq.top()).second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
}
