string kthPermutation(int n, int k) 
{
    // Write your code here.
    int fact = 1;
    string nums = "1", ans;
    for(int i = 1; i < n; i++)
    {
        fact *= i;
        nums.push_back(char((int)'1' + i));
    }
    k--;
    while(nums.length())
    {
        int ind = k / fact;
        ans.push_back(nums[ind]);
        nums.erase(nums.begin() + ind);     
        k %= fact;
        if(nums.length())
        fact /= nums.length();
    }
    return ans;
}
