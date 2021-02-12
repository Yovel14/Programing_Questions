// Time : O(log2(n)+1) = O(log2(n)) the last on bit n (log2(n)+1 <=32)
// Space : O(1)
int numberOfSteps(int n)
{
	int count = 0;
	while (n)
	{
		while (n && n & 1 ^ 1)
		{
			count++;
			n >>= 1;
		}
		if (n)
		{
			count++;
			n ^= 1;
		}
	}
	return count;
}

// Time : O(1)
// Space : O(1)
int numberOfSteps(int n)
{
	return n ? 32 - __builtin_clz(n) - 1   // same as int(log2(n))
				   + __builtin_popcount(n) // number of 1 bits
			 : 0;
}