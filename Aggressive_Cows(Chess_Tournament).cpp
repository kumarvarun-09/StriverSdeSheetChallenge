// CODESTUDIO CODE

#include<limits.h>
bool isValid(vector<int> &pos, int players, long long mid)
{
    int n = pos.size(), count = 1;
    long long lastPos = pos.front();
    for(int i = 1; i < n; i++)
    {        
        if(pos[i] - lastPos >= mid)
        {
            lastPos = pos[i];
            count++;
        }
    }
    return (count >= players);
}

int chessTournament(vector<int> positions, int n, int players){
	// Write your code here
    sort(positions.begin(), positions.end());
    long long low = 0, high = positions.back() - positions.front(), mid, ans = 0;
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        if(isValid(positions, players, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }

    return ans;
}


// SPOJ PROBLEM CODE 


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Vi vector<int>
#define Vll vector<long long>

bool isValid(ll minDis, int cows, Vi &v)
{
    int n = v.size();
    int lastP = v[0];
    cows--; // places the first cow at position v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] - lastP >= minDis)
        {
            lastP = v[i];
            cows--;
        }
        if (!cows)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        Vi v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        ll low = 0, high = 10e9, mid;
        while ((high - low) > 1)
        {
            mid = low + (high - low) / 2;
            if (isValid(mid, c, v))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (isValid(high, c, v))
        {
            cout << high << endl;
        }
        else
        {
            cout << low << endl;
        }
    }
    return 0;
}
