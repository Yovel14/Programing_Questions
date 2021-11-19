// Time : O(n)
// Space : O(n)
int minOperations(int n)
{
	if (n & 1)
		return n / 2 * (n / 2 + 1);
	return (n / 2) * (n / 2);
}