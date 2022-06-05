#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long ans = LONG_LONG_MIN, temp = 0;
    for(int i = 0; i < n; i++)
    {
        temp += arr[i];
        if(temp < 0)
            temp = 0;
        ans = max(ans, temp);
    }
    return ans;
}
