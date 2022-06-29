bool isValid(vector<int>&time, int days, long long mid)
{
    int n = time.size();
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(sum + time[i] <= mid)
        {
            sum += time[i];
        }
        else
        {
            sum = time[i];
            days--;
        }
        if(!days)
            return false;
    }
    return true;
}

long long ayushGivesNinjatest(int days, int chapters, vector<int> time) 
{	
	// Write your code here.
    long long low = 0, high = 0, mid;
    for(long long x: time)
    {
        low = max(low, x);
        high += x;
    }
    while(low < high)
    {
        mid = low + (high - low) / 2;
        if(isValid(time, days, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    if(isValid(time, days, low))
        return low;
    
    return high;
}
