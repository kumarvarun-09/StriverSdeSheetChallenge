#include<queue>
vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int C) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto x: A)
    {
        for(auto y: B)
        {
            int sum = x + y;
            if(pq.size() < C)
            pq.push(sum);
            else if(pq.top() < sum)
            {
                pq.pop();
                pq.push(sum);
            }
        }
    }
    vector<int> ans(C);
    for(int i = C - 1; i >= 0; i--)
    {
        ans[i] = pq.top();
        pq.pop();
    }
    return ans;
}
