#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    int left = 0, right = n - 1;
    long long ans = 0, leftmax = 0, rightmax = 0;
    
    while(left <= right)
    {
        if(arr[left] <= arr[right])
        {
            if(arr[left] >= leftmax)
            {// it means the current height can not store water because it is greater than previous maximums
                leftmax = arr[left];
            }
            else
            {//it means the current height can store some water
                ans += (leftmax - arr[left]);
            }
            left++;
        }
        else
        {
            if(arr[right] >= rightmax)
            {// it means the current height can not store water because it is greater than previous maximums
                rightmax = arr[right];
            }
            else
            {//it means the current height can store some water
                ans += (rightmax - arr[right]);
            }
            right--;
        }
    }
    return ans;
}
