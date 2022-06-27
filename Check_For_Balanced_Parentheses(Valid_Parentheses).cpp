bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    for(auto x: expression)
    {
        if(x == '(' || x == '{' || x == '[')
        {
            st.push(x);
        }
        else if(st.size())
        {
            if((x == ')' && st.top() == '(') || (x == '}' && st.top() == '{') || (x == ']' && st.top() == '['))
                st.pop();
            else
                return false;
        }
        else
        {
            return false;
        }
    }
    return st.empty();
}
