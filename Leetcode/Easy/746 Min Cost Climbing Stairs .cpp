int minCostClimbingStairs(vector<int> &cost) // with changing vector
{
	int n = cost.size();
	for (int i = 2; i < n; i++)
		cost[i] += min(cost[i - 1], cost[i - 2]);

	return min(cost[n - 1], cost[n - 2]);
}

int minCostClimbingStairs(vector<int> &cost) // without changing vector
{
	int n = cost.size();
	int c1 = cost[1];
	int c2 = cost[0];
	int temp;
	for (int i = 2; i < n; i++)
	{
		temp = min(c1, c2) + cost[i];
		c2 = c1;
		c1 = temp;
	}
	return min(c1, c2);
}