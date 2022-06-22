int findMinimumCoins(int amount) 
{
    // Write your code here
    int currency[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; // index of last block will be 8
    int atemp = amount, coins = 0;
    for(int i = 8; i >= 0 && atemp; i--)
    {
        coins += (atemp / currency[i]);
        atemp %= currency[i];
    }
    return coins;
}
