// Time : O(log2(n))
// Space : O(1)
int brokenCalc(int x, int y)
{
	int count = 0;
	while (y > x)
	{
		if (y & 1)
			y++; // make even
		else
			y >>= 1; // devide by two
		count++;
	}
	return count + x - y; // for when deviding by 2 gives a number smaller than x
}