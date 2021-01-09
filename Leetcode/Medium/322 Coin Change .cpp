// dp
int coinChange(vector<int> &coins, int amount)
{
	if (amount == 0)
		return 0;
	int a[++amount];
	a[0] = 0;

	sort(coins.begin(), coins.end()); // sorting to be able to skip the coins once they are bigger than i thus shortning the time

	for (int i = 1; i < amount; ++i)
	{
		a[i] = -1;
		for (int &coin : coins)
		{
			if (i < coin)
				break;

			if (a[i - coin] != -1)
			{ // I am testing for min value and -1 will always be

				if (a[i] == -1)
					a[i] = a[i - coin] + 1; // if a[i] is -1 it will always be the min value

				else if (a[i - coin] + 1 < a[i]) // checking for min value
					a[i] = a[i - coin] + 1;
			}
		}
	}
	return a[amount - 1];
}

// dp
int coinChange(vector<int> &coins, int amount)
{
	if (amount == 0)
		return 0;

	sort(coins.begin(), coins.end());
	if (amount < coins[0])
		return -1;

	int a[amount + 1];
	a[0] = 0;

	for (int i = 1; i < amount + 1; i++)
	{
		a[i] = INT_MAX;
		for (int &coin : coins)
		{
			if (i < coin)
				break;
			if (a[i - coin] != INT_MAX)
				a[i] = min(a[i], a[i - coin] + 1);
		}
	}

	if (a[amount] == INT_MAX)
		return -1;
	return a[amount];
}

// recursive

void solve(vector<int> &coins, int amount, int index, int cur_count, int &mn)
{
	if (amount % coins[index] == 0)
	{
		mn = min(cur_count + amount / coins[index], mn);
		return;
	}

	if (index == 0)
		return;

	int i = amount / coins[index];
	for (int sum = i * coins[index]; sum >= 0; sum -= coins[index])
	{
		if (i + cur_count + 1 >= mn)
			return;
		solve(coins, amount - sum, index - 1, cur_count + i, mn);
		i--;
	}
}

int coinChange(vector<int> &coins, int amount)
{
	if (amount == 0)
		return 0;
	if (coins.size() == 0)
		return -1;
	sort(coins.begin(), coins.end());
	int mn = INT_MAX;
	solve(coins, amount, coins.size() - 1, 0, mn);

	if (mn == INT_MAX)
		return -1;
	return mn;
}