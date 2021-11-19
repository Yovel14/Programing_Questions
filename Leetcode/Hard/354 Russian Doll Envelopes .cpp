// iterative dp with binary search
// Time : O(n log2(n))
// Time : O(n)
static bool inline comp(vector<int> &a, vector<int> &b)
{
	return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
}

int inline maxEnvelopes(vector<vector<int>> env)
{
	if (env.size() < 2)
		return env.size();
	sort(env.begin(), env.end(), comp);

	vector<int> dp;
	for (vector<int> &v : env)
	{
		vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), v[1]);
		if (it == dp.end())
			dp.push_back(v[1]);
		else
			(*it) = v[1];
	}

	return dp.size();
}

// iterative dp
// Time : O(n^2)
// Time : O(n)
static bool inline comp(vector<int> &a, vector<int> &b)
{
	return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}

int inline maxEnvelopes(vector<vector<int>> env)
{
	if (env.size() < 2)
		return env.size();
	sort(env.begin(), env.end(), comp);

	int n = env.size();
	int dp[n];

	int mx = 0;
	for (int b = n - 1; b != -1; b--)
	{
		dp[b] = 1;
		for (int i = b + 1; i < n; i++)
			if (env[b][0] < env[i][0] && env[b][1] < env[i][1])
				dp[b] = max(dp[b], dp[i] + 1);
		mx = max(mx, dp[b]);
	}

	return mx;
}

// memoization dp
// Time : O(n^2)
// Time : O(n)
static bool inline comp(vector<int> &a, vector<int> &b)
{
	return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}
int dfs(vector<vector<int>> &env, int index, int dp[])
{
	if (index == env.size())
		return 0;

	if (dp[index] != -1)
		return dp[index];

	int mx_depth = 0;
	for (int i = index + 1; i < env.size(); i++)
		if (env[index][0] < env[i][0] && env[index][1] < env[i][1])
			mx_depth = max(mx_depth, dfs(env, i, dp));

	return dp[index] = mx_depth + 1;
}

int inline maxEnvelopes(vector<vector<int>> env)
{
	if (env.size() < 2)
		return env.size();
	sort(env.begin(), env.end(), comp);

	int dp[env.size()];
	memset(dp, -1, sizeof(dp));
	int mx = 0;
	for (int i = 0; i < env.size(); i++)
		if (dp[i] == -1)
			mx = max(mx, dfs(env, i, dp));
	return mx;
}