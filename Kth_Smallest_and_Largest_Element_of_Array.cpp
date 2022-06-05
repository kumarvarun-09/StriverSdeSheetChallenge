#include<set>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	set<int> st;
	for(int i = 0; i < n; i++)
	{
		st.insert(arr[i]);
	}
	vector<int> v, ans;
    for(auto x: st)
	{
		v.push_back(x);
	}
	ans.push_back(v[k - 1]);
	ans.push_back(v[v.size() - k]);
	return ans;
}
