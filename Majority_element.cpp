#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int s) {
	// Write your code here
        int n = s / 2;
        unordered_map<int, int> mp;
        for(int i = 0; i < s; i++)
        {
            mp[arr[i]]++;
        }
        for(auto x: mp)
        {
            if(x.second > n)
                return x.first;
        }
        return -1;
}
