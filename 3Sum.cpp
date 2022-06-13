#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++)
    {
        int trgt = K - arr[i], s = i + 1, e = n - 1;
        while(s < e)
        {
            int el1 = arr[s], el2 = arr[e];
            if(el1 + el2 < trgt)
                s++;
            else if(el1 + el2 > trgt)
                e--;
            else
            {
                vector<int> v = {arr[i], el1, el2};
                ans.push_back(v);
                while(s < e && arr[s] == el1)
                    s++;
                while(s < e && arr[e] == el2)
                    e--;
            }
        }
        while(i < n - 1 && arr[i] == arr[i + 1])
            i++;
    }
    return ans;
}
