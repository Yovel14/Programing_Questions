// Time : O(5^n)
// Space : O(5) = O(1)
int solve(int n, int index, vector<char> &ch)
{
	if (n == 0)
		return 1;
	if (index >= 5)
		return 0;

	int ans = 0;
	for (int i = index; i < 5; i++)
	{
		ans += solve(n - 1, i, ch);
	}

	return ans;
}
int countVowelStrings(int n)
{
	vector<char> ch = {'a', 'e', 'i', 'o', 'u'};
	return solve(n, 0, ch);
}

// dp memozation
// Time : O(5*n) = O(n)
// Space : O(5*n) = O(n)
int solve(int n, int index, vector<char> &ch, vector<vector<int>> &dp)
{
	if (n == 0)
		return 1;
	if (index >= 5)
		return 0;
	if (dp[index][n] != -1)
		return dp[index][n];

	int ans = 0;
	for (int i = index; i < 5; i++)
	{
		ans += solve(n - 1, i, ch, dp);
	}

	return dp[index][n] = ans;
}
int countVowelStrings(int n)
{
	vector<char> ch = {'a', 'e', 'i', 'o', 'u'};
	vector<vector<int>> dp(5, vector<int>(n + 1, -1));
	return solve(n, 0, ch, dp);
}

// dp tabulation
// Time : O(n*5) = O(n)
// spce : O(n*5) = O(n)
int countVowelStrings(int n)
{
	if (n == 0)
		return 0;

	vector<vector<int>> dp(5, vector<int>(n));
	for (int li = 0; li < n; li++)
		dp[0][li] = 1;
	for (int vi = 1; vi < 5; vi++)
		dp[vi][0] = vi + 1;

	for (int vi = 1; vi < 5; vi++)
	{
		for (int li = 1; li < n; li++)
		{
			dp[vi][li] = dp[vi - 1][li] + dp[vi][li - 1];
		}
	}
	return dp[4][n - 1];
}

// better dp tabulation
// Time : O(n*5) = O(n)
// Space : O(5) = O(1)
int countVowelStrings(int n)
{
	vector<int> dp(5);
	for (int i = 0; i < 5; i++)
		dp[i] = i + 1;

	for (int li = 1; li < n; li++)
		for (int vi = 1; vi < 5; vi++)
			dp[vi] += dp[vi - 1];
	return dp[4];
}

// math
// Time : O(1)
// Space : O(1)
int countVowelStrings(int n)
{
	// to get to the soluiontion
	// represent vowels to numbers
	// and do a simple check
	// n = 2 : 11,12,13,14,15,22,23,24,25,33,34,35,44,45,55
	// so it actually the number of combinations with repitations and there is a formula for that
	// (n+k-1)!/(k! * (n-1)!)
	// and after subsatuation it get's to the below formula
	return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
}