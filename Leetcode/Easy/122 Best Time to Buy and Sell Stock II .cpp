// greedy
int maxProfit(vector<int> &prices)
{
	// since I can buy as much as I want why not but at each location that is smaller than is next and if 1 , 7 ,8 I can but at 1 and sell at 2 and but at 2 and sell at 3
	int sum = 0;
	int n = prices.size();
	for (int i = 1; i < n; i++)
		if (prices[i] > prices[i - 1])
			sum += prices[i] - prices[i - 1];
	return sum;
}

// peaks and valleys
int maxProfit(vector<int> &prices)
{
	int sm = 0;
	int i = 0;
	int n = prices.size() - 1;
	int peak = prices[0];
	int valley = prices[0];
	while (i < n)
	{
		while (i < n && prices[i] >= prices[i + 1])
			i++;
		valley = prices[i];
		while (i < n && prices[i] <= prices[i + 1])
			i++;
		peak = prices[i];
		sm += peak - valley;
	}

	return sm;
}

// brute force -- TLE
int solve(vector<int> &prices, int index)
{
	if (index == prices.size())
		return 0;

	int mx = 0;
	int cur;
	int n = prices.size();

	for (int i = index; i < n; i++)
	{
		cur = 0;
		for (int j = i + 1; j < n; j++)
			if (prices[i] < prices[j])
				cur = max(cur, solve(prices, j + 1) + prices[j] - prices[i]);
		if (cur > mx)
			mx = cur;
	}

	return mx;
}
int maxProfit(vector<int> &prices)
{
	return solve(prices, 0);
}