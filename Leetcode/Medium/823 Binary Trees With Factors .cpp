// Time : O(n^2)
// Space : O(n)
int numFactoredBinaryTrees(vector<int> &arr)
{
	int n = arr.size();
	if (n == 0)
		return 0;
	long dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = 1;
	const int mod = 1000000007;
	sort(arr.begin(), arr.end());
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
		m[arr[i]] = i;

	unordered_map<int, int>::iterator it;
	int sum = 0; // 1 because of dp[0]
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] % arr[j] == 0)
			{
				it = m.find(arr[i] / arr[j]);
				if (it != m.end())
					dp[i] = (dp[i] + dp[j] * dp[it->second]) % mod;
			}
		}
		sum = (dp[i] + sum) % mod;
	}

	return sum;
}

// Improved the avove solution
// Time : O(n^2)
// Space : O(n)
// this solution is improved by the fact that things happen twice one on the first half of numbers smaller than sqrt of arr[i] and on the other side (not including when arr[j] == sqrt(arr[i]) the arr[i] has a perfect sqrt)
int numFactoredBinaryTrees(vector<int> &arr)
{
	int n = arr.size();
	if (n == 0)
		return 0;
	long dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = 1;
	const int mod = 1000000007;
	sort(arr.begin(), arr.end());
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
		m[arr[i]] = i;

	unordered_map<int, int>::iterator it;
	int sum = 0; // 1 because of dp[0]
	int sq;
	long tmp;
	for (int i = 0; i < n; i++)
	{
		sq = sqrt(arr[i]);
		for (int j = 0; arr[j] <= sq; j++)
		{
			if (arr[i] % arr[j] == 0)
			{
				it = m.find(arr[i] / arr[j]);
				if (it != m.end())
				{
					tmp = ((dp[j] * dp[it->second]) % mod);
					if (arr[j] != sq || (arr[j] * arr[j] != arr[i]))
						dp[i] = (dp[i] + (tmp << 1)) % mod;
					else
						dp[i] = (dp[i] + tmp) % mod;
				}
			}
		}
		sum = (dp[i] + sum) % mod;
	}

	return sum;
}