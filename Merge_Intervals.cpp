#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &interval)
{
    // Write your code here.
        int n = interval.size();
        sort(interval.begin(), interval.end());
        vector<vector<int>> ans;
        vector<int> temp(interval.front());
        for(int i = 1; i < n; i++)
        {
            if(interval[i][0] > temp[1])
            {
                ans.push_back(temp);
                temp = interval[i];
            }
            if(interval[i][0] <= temp[1] && temp[1] <= interval[i][1])
            {
                temp[1] = interval[i][1];
            }
        }
        ans.push_back(temp);
        return ans;
}
