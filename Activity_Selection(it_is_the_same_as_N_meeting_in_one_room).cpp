#include<algorithm>
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    // Write your code here.
    int n = start.size();
    vector<pair<int, int>> ds;
    for (int i = 0; i < n; i++)
    {
        ds.push_back({finish[i], start[i]});
    }
    sort(ds.begin(), ds.end());
    int maxi = ds[0].first, count = 1; // count is initialized with 1 because we have already included the first activity and we starting traversal in ds from index 1
    for (int i = 1; i < n; i++)
    {
        if (ds[i].second >= maxi) // ds[i].second  --->  start
        {
          // (ds[i].second >= maxi)   because A person can only work on a single activity at a time. The start time of one activity can coincide with the end time of another.
            maxi = ds[i].first; // ds[i].first  --->  finish
            count++;
        }
    }
    return count;
}
