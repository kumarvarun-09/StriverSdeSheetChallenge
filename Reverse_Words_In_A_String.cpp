string reverseString(string str)
{
    // Write your code here.
    string ans;
    for(int i = str.length() - 1; i >= 0; i--)
    {
        if(i && str[i] != ' ')
            continue;
        
        int j = i;// if i == 0 or if str[i] == ' '
        if(str[i] == ' ')
            j = j + 1;//we don't want to use white space so we'll start using string from the next character
        if(ans.length() && ans.back() != ' ')
            ans.push_back(' ');
            
        while(j < str.length()) // here it iis confirm that the at index initial j, the string is not having ' '
        {
            if(str[j] == ' ')
                break;
            ans.push_back(str[j]);
            j++;
        }
    }
    if(ans.length() && ans.back() == ' ')
        ans.pop_back();
    
    return ans;
}
