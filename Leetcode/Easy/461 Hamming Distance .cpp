// Time : O(k) where k is the number of bits
// Space: O(1)
int hammingDistance(int x, int y)
{
	return __builtin_popcount(x ^ y);
}

// Time : O(k) where k is the number of bits
// Space: O(1)
int hammingDistance(int x, int y)
{
	int xr = x ^ y;

	int count = 0;
	while (xr)
	{
		count++;
		xr &= xr - 1; // remove the right most bit
	}

	return count;
}