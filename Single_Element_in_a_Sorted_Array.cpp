int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    if(n == 1)
        return arr.front();
    
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(mid & 1)
        {
            if(arr[mid] == arr[mid - 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else
        {
            if(arr[mid] == arr[mid + 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return arr[low];
}
