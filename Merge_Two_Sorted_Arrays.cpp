#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) 
{
	// Write your code here.
       int s = m + n, i = m - 1, j = n - 1;
        while(s--)
        {
            if(i >= 0 && j >= 0)
            { 
                if(nums1[i] > nums2[j])
                {
                    nums1[s] = nums1[i];
                    i--;
                }
                else
                {
                    nums1[s] = nums2[j];
                    j--;
                }
            }
            else if(j >= 0)
            {
                   nums1[s] = nums2[j];
                   j--;
            }
        }
    return nums1;
}
