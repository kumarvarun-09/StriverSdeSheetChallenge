bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int map[26] = {0};
    for(auto x: str1)
    {
        map[x - 'a']++;
    }
    for(auto x: str2)
    {
        map[x - 'a']--;
    }
    for(auto x: map)
    {
        if(x)
            return false;
    }
    return true;
}
