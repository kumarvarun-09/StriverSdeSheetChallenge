int getCount(vector<int> &v, int num)
{
    int l = 0, r = v.size() - 1;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(v[mid] <= num)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low = 1, high = 1e5 + 10, row = matrix.size(), col = matrix[0].size();
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = 0;
        for(int i = 0; i < row; i++)
        {
            count += getCount(matrix[i], mid);
        }
        if(count <= (row * col) / 2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
