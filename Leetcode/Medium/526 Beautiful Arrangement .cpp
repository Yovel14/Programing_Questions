// brute force / recurseive solution
int countArrangement(int n)
{
	int count = 0;
	bool used[16] = {0};
	solve(n, 1, count, used);
	return count;
}
void solve(int n, int index, int &count, bool used[])
{
	if (index > n)
		count++;
	for (int i = 1; i <= n; i++)
	{
		if (!used[i] && (i % index == 0 || index % i == 0))
		{
			used[i] = true;
			solve(n, index + 1, count, used);
			used[i] = false;
		}
	}
}