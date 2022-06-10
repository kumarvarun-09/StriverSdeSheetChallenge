#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int ans = 1, count = 1;
    sort(arr.begin(), arr.end());
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == arr[i - 1])
            continue;
        if(arr[i] == arr[i - 1] + 1)
            count++;
        else
            count = 1;
        
        ans = max(ans, count);
    }
    return ans;
}
