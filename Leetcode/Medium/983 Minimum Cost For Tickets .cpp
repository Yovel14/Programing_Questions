// memoized 1
int solve(int i, unordered_set<int> &days, int dp[], vector<int> &costs)
{
	if (i > 365)
		return 0;
	if (dp[i] != -1)
		return dp[i];

	if (days.find(i) == days.end())
		return dp[i] = solve(i + 1, days, dp, costs);

	int ans;
	ans = solve(i + 1, days, dp, costs) + costs[0];
	ans = min(ans, solve(i + 7, days, dp, costs) + costs[1]);
	ans = min(ans, solve(i + 30, days, dp, costs) + costs[2]);

	return dp[i] = ans;
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
	unordered_set<int> day;
	for (int &d : days)
		day.insert(d);

	int dp[366];
	memset(dp, -1, sizeof(dp));

	return solve(1, day, dp, costs);
}

// memoized 2
int solve(int i, vector<int> &days, vector<int> &costs, int dp[], int duration[])
{
	if (i >= days.size())
		return 0;
	if (dp[i] != -1)
		return dp[i];

	int ans = INT_MAX;
	int j = i;
	for (int k = 0; k < 3; k++)
	{
		while (j < days.size() && days[j] < days[i] + duration[k])
			j++;
		ans = min(ans, solve(j, days, costs, dp, duration) + costs[k]);
	}
	return dp[i] = ans;
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
	int dp[days.size()];
	memset(dp, -1, sizeof(dp));
	int duration[] = {1, 7, 30};
	return solve(0, days, costs, dp, duration);
}

// tabulation
int mincostTickets(vector<int> &days, vector<int> &costs)
{
	unordered_set<int> day;
	for (int &d : days)
		day.insert(d);

	int dp[396] = {0};

	for (int i = 365; i >= 1; i--)
	{
		if (day.find(i) != day.end())
			dp[i] = min(dp[i + 1] + costs[0], min(dp[i + 7] + costs[1], dp[i + 30] + costs[2]));
		else
			dp[i] = dp[i + 1];
	}
	return dp[1];
}