#include <bits/stdc++.h> 
long long mergeTwoSortedArrays(long long *v, const int l, const int r)
{
    int mid = l + (r - l) / 2;
    int i = l, j = mid + 1;
    vector<int> ans;
    long long icount = 0;
    while (i <= mid && j <= r)
    {
        if (v[i] <= v[j])
        {
            ans.push_back(v[i]);
            i++;
        }
        else
        {
            ans.push_back(v[j]);
            j++;
            icount += (mid + 1 - i);
            // here we find that the v[j] element is greater than initial (i - 1) elements but smaller than the rest (mid + 1 - i) but still present in the right array of them, that is why we are increasing count1 by (mid + 1 - i)
            // Yes this is a little bit tricky
            
//             Example: n = 10, i = 0, mid = 4, j =  (mid + 1) = 5, r = 9
//             Here there are 5 elements present before j, so we should write icount += (mid - i + 1);
        }
    }
    while (i <= mid)
    { // if left array is greater than right array
        ans.push_back(v[i]);
        i++;
    }
    while (j <= r)
    { // if right array is greater than left array
        ans.push_back(v[j]);
        j++;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        v[l + i] = ans[i];
    }
    return icount;
}
long long mergeSort(long long *v, const int l, const int r)
{
    if (l >= r)
        return 0;
    int mid = l + (r - l) / 2;
    long long ic1 = mergeSort(v, l, mid);
    long long ic2 = mergeSort(v, mid + 1, r);
    return ic1 + ic2 + mergeTwoSortedArrays(v, l, r);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr, 0, n - 1);
}
