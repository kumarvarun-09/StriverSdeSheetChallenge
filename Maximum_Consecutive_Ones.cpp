int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i = 0, j = 0, ans = 0, ktemp = k;
    while(i < n && j < n)
    {
        if(arr[j] == 1)
        {
            j++;
            ans = max(ans, j - i);
        }
        else if(arr[j] == 0)
        {
            if(ktemp)
            {
                ktemp--;
                j++;
                ans = max(ans, j - i);
            }
            else 
            {
                if(arr[i] == 0)
                {
                    if(ktemp < k)
                        ktemp++;
                }
                i++;
            }
        }        
    }
    return ans;
}
