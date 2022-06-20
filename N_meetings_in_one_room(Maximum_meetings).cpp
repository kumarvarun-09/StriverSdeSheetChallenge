#include<algorithm>
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    vector<vector<int>> ds;
    for(int i = 0; i < n; i++)
    {
        vector<int> temp = {end[i], i + 1, start[i]}; 
        ds.push_back(temp);
    }
    sort(ds.begin(), ds.end());
    int mxend = ds[0][0];
    vector<int> ans = {ds[0][1]};
    
//     ds[i][0] ---> end[i];
//     ds[i][1] ---> i + 1;   // index
//     ds[i][2] ---> start[i];
    
    for(int i = 1; i < n; i++)
    {
        if(ds[i][2] > mxend)
        {
            ans.push_back(ds[i][1]);
            mxend = ds[i][0];
        }
    }
    return ans;
}
