#include<stack>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> st;
    vector<int> ans(arr.size(), -1);
    for(int i = n - 1; i >= 0; i--)
    {
        while(st.size() && st.top() <= arr[i])
        {
            st.pop();
        }
        if(st.size() && st.top() > arr[i])
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
