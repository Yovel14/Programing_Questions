// Time : O(n)
// Spcace : O(n)
vector<int> constructArray(int n, int k)
{
	vector<int> ans(n);
	bool startTurn = k & 1; // in order to make sure I am ending with s as the value before adding other numbers so the difference will be 1
	int s = 1, e = n;
	int p = 0;
	while (k--)
	{
		if (startTurn)
			ans[p++] = s++;
		else
			ans[p++] = e--;
		startTurn = !startTurn;
	}

	while (s <= e)
		ans[p++] = s++;

	return ans;
}

// Time : O(n)
// Space  : O(n)
vector<int> constructArray(int n, int k)
{
	vector<int> ans(n);
	int p = 0;
	for (int s = 1; s < n - k; s++)
		ans[p++] = s;

	for (int i = 0; i <= k; i++)
		ans[p++] = i & 1 ? n - i / 2 : n - k + i / 2;

	return ans;
}