#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    set<char> st;
    int l = 0, r = 0, ans  = 0;
    for(auto x: input)
    {
        while(st.find(x) != st.end())
        {
            st.erase(st.find(input[l]));
            l++;
        }
        ans = max(ans, r - l + 1);
        st.insert(x);
        r++;
    }
    return ans;
}
