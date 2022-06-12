#include<limits.h>
int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    int temp = INT_MAX, repeat = 0;
    for(auto x: arr)
    {
        if(x == temp)
            repeat++;
        temp = x;
    }
    return arr.size() - repeat;
}
