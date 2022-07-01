#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto &x: kArrays)
    {
        for(auto y: x)
        {
            pq.push(y);
        }
    }
    vector<int> ans;
    while(pq.size())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
