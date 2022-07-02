#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    
    for(int i = 0; i < n; i++)
    {
        
            if(maxHeap.empty() || arr[i] <= maxHeap.top())
                maxHeap.push(arr[i]); // insert at left🙄🙄
            else
                minHeap.push(arr[i]);
        
            while(maxHeap.size() > minHeap.size())
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            while(maxHeap.size() < minHeap.size())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        
        if(i&1)// means the sum of sizes of minHeap ans maxHeap is even  
        {
            cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
        }
        else
        {
            cout << maxHeap.top() << " ";
        }
    }
}
