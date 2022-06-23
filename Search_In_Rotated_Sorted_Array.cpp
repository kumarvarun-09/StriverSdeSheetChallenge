int findPivot(int *arr, int n)
{
    // uisng smaller number as pivot
    int l = 0, r = n - 1, mid = 0;
    while(l < r)
    {
        mid = l + (r - l) / 2;
        if(arr[mid] >= arr[r])
            l = mid + 1;
        else if(arr[mid] < arr[r])
            r = mid;
    }
    return l;
}
int search(int* arr, int n, int key) {
    // Write your code here.
    int pivot = findPivot(arr, n), ans = -1;
    if(key <= arr[n - 1])
    {
        auto it = lower_bound(arr + pivot, arr + n, key);
        if(*it == key)
        { 
            ans = it - arr;
        }
    }
    else if(pivot && key >= arr[0])
    {
        auto it = lower_bound(arr, arr + pivot, key);
        if(*it == key)
        { 
            ans = it - arr;
        }
    }
    return ans;
}
