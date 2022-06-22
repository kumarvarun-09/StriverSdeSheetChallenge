// CODESTUDIO PROBLEM CODE


#include<algorithm>
bool comparator(pair<int, int> &a, pair<int, int> &b)
{
    // ITEMS contains {weight, value} pairs.
    double avgA = ((double)a.second) / a.first;
    double avgB = ((double)b.second) / b.first;
    return avgA > avgB;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comparator);
    double ans = 0;
    for(int i = 0; i < n ; i++)
    {
        if(w - items[i].first >= 0)
        {
            w -= items[i].first;
            ans += items[i].second;
        }
        else
        {
            ans += ((((double)items[i].second) / items[i].first) * w);
            w = 0;
        }
    }
    return ans;
}



_____________________________________________________________________________________________________________________________________________________________________________________________________
  
  
  
  
  // GFG PROBLEM CODE
  
  
  
 // { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comparator(Item a, Item b)
    {
        double avg1 = (double)a.value / a.weight;
        double avg2 = (double)b.value / b.weight;
        return (avg1 > avg2);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, comparator);
        double value = 0;
        for(int i = 0; i < n && W; i++)
        {
            if(W - arr[i].weight >= 0)
            {
                W -= arr[i].weight;
                value += arr[i].value;
            }
            else
            {
                value += ((arr[i].value / (double)arr[i].weight) * W);
                W = 0;
            }
        }
        return value;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
