void sort012(int *arr, int n)
{
   //   Write your code here
	int _0 = 0, _1 = 0, _2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(!arr[i])
			_0++;
		else if(arr[i]&1)
			_1++;
		else
			_2++;
	}
	for(int i = 0; i < n; i++)
	{
		if(_0)
		{
			arr[i] = 0;
			_0--;
		}
		else if(_1)
		{
			arr[i] = 1;
			_1--;
		}
		else 
		{
			arr[i] = 2;
			_2--;
		}
	}
}
