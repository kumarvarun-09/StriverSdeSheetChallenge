int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);
    
    int countmax = 1, count = 1, i = 1, j = 0;
    while(i < n && j < n)
    {
        if(at[i] <= dt[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        countmax = max(countmax, count);
    }
    return countmax;
}
