#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    sort(arr.begin(), arr.end());
    vector<int> pairsum(2);
    vector<vector<int>> ans;
    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] + arr[j] == s)
            {
                pairsum[0] = arr[i];
                pairsum[1] = arr[j];
                ans.push_back(pairsum);
            }
        }
    }
    return ans;
}
