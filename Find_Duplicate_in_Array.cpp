#include <bits/stdc++.h> 
int findDuplicate(vector<int> &nums, int n){
	// Write your code here.
    for(int i = 0; i < n; i++)
    {
        int t = abs(nums[i]) - 1;
        if(nums[t] < 0)
            return t + 1;
        else
            nums[t] = -nums[t];
    }
    return 0;
}
