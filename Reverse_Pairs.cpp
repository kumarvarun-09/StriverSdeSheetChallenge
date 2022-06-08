#include <bits/stdc++.h> 
int merge(vector<int> &v, int l, int r)
{
    int mid = l + (r - l) / 2;
    int i = l, j = mid + 1, count = 0;
    while(i <= mid && j <= r)
    {
        if((long long)v[i] <= 2 * (long long)v[j])
        {
            i++;
        }
        else
        {
            count += (mid - i + 1);
            j++;
        }
    }
    i = l, j = mid + 1;
    vector<int> ans;
    while(i <= mid && j <= r)
    {
        if(v[i] <= v[j])
        {
            ans.push_back(v[i]);
            i++;
        }
        else
        {
            ans.push_back(v[j]);
            j++;
        }  
    }
    while(i <= mid)
    {
        ans.push_back(v[i]);
        i++;
    }
    while(j <= r)
    {
        ans.push_back(v[j]);
        j++;
    }
    for(int i = 0; i < ans.size(); i++)
    {
        v[l + i] = ans[i];
    }
    return count;
}
int mergeSort(vector<int> &v, int l, int r)
{
    if(l >= r)
        return 0;
    int mid = l + (r - l) / 2;
    return mergeSort(v, l, mid) + mergeSort(v, mid + 1, r) + merge(v, l, r);
}
int reversePairs(vector<int> &arr, int n)
{
	// Write your code here.	
    return mergeSort(arr, 0, n - 1);
}
