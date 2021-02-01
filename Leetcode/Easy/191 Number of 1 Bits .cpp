// Time : O(32) = O(1)
// Space : O(1)
int hammingWeight(uint32_t n)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
		if ((n >> i) & 1)
			count++;
	return count;
}

// improved the first just without the for loop
// Time : O(32) = O(1)
// Space : O(1)
int hammingWeight(uint32_t n)
{
	int count = 0;
	while (n)
	{
		count += n & 1;
		n >>= 1;
	}
	return count;
}

// Time : O(count1) count1 if the number of 1 bits in n
int hammingWeight(uint32_t n)
{
	int count = 0;
	while (n)
	{
		n &= (n - 1); // remove the last bit
		count++;
	}
	return count;
}