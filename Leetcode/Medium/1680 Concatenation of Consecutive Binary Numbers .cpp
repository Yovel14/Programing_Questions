// Time : O(n)
// Space : O(1)
int concatenatedBinary(int n)
{
	long ans = 0;
	int mod = 1e9 + 7;
	int length = 0;
	for (int i = 1; i <= n; i++)
	{
		if ((i & (i - 1)) == 0) // is i a power of 2
			length++;
		ans = (ans << length) % mod;
		if (ans > mod - i)
			ans -= mod;
		ans += i;
	}
	return ans;
}