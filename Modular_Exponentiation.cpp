#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    if(!n)
        return 1;
    int temp = 1;
    if(n & 1)
        temp = x % m;
    long long exp = modularExponentiation(x % m, n / 2, m);
    exp %= m;
    exp = (exp * exp) % m;
        return (temp * exp) % m;
}
