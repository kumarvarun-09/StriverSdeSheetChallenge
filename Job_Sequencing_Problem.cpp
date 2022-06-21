// CODESTUDIO PROBLEM CODE



#include<algorithm>
bool comparator(vector<int> a, vector<int> b)
{
    return (a[1] > b[1]);
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n = jobs.size(), count = n, sum = 0;
    sort(jobs.begin(), jobs.end(), comparator);
    vector<int> hash(3000, -1);
    for(int i = 0; i < n; i++)
    {
        if(count)
        {
            int j = jobs[i][0] - 1;
            while(j && hash[j] != -1)
            {
                j--;
            }
            if(hash[j] == -1)
            {
                hash[j] = jobs[i][1];
                sum += jobs[i][1];
                count--;
            }
        }
        else
        {
            break;
        }
    }
    return sum;
}



___________________________________________________________________________________________________________________________________________________________________________
  
  
  
  
  
  // GFG QUESTION CODE
  
  
  
  
  // { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job a, Job b)
    {
        return (a.profit > b.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr + n, comparator);
        vector<int> hash(n, -1);
        int count = n, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(count)
            {
                int j = arr[i].dead - 1;
                while(j && hash[j] != -1)
                {
                    j--;
                }
                if(hash[j] == -1)
                {
                    hash[j] = arr[i].id;
                    sum += arr[i].profit;
                    count--;
                }
            }
            else
            {
                break;
            }
        }
        return {n - count, sum};      
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends
