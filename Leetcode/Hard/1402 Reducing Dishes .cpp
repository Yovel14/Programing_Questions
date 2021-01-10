int maxSatisfaction(vector<int> &sat) // O(n^2)
{
	sort(sat.begin(), sat.end());

	int n = sat.size();
	int cur;
	int mx = INT_MIN;
	int dish_index;
	for (int i = n - 1; i >= 0; i--)
	{
		cur = 0;
		dish_index = 1;
		for (int j = i; j < n; j++, dish_index++)
		{
			cur += sat[j] * dish_index;
		}
		if (cur > mx)
			mx = cur;
		else
			break;
	}
	return max(mx, 0);
}

// O(nlog(n)
int sat_sum(vector<int> &sat, int &i)
{
	int index = 1;
	int sum = 0;
	for (; i < sat.size(); i++, index++)
		sum += sat[i] * index;
	return sum;
}
int maxSatisfaction(vector<int> &sat)
{
	sort(sat.begin(), sat.end());

	int n = sat.size();
	int cur;
	int mx = INT_MIN;
	int dish_index;
	int low = 0, high = n;
	int mid;
	while (low < high)
	{
		mid = low + ((high - low) >> 1);

		if (sat_sum(sat, mid) >= sat_sum(sat, mid + 1)) // find peak
			high = mid;
		else
			low = mid + 1;
	}

	return max(mx, sat_sum(sat, low));
}

// O(nlog(n)) improved
int maxSatisfaction(vector<int> &sat)
{
	sort(sat.begin(), sat.end());

	int cur_sum = 0;
	int mx = 0;
	for (int i = sat.size() - 1; i >= 0; i--)
	{
		cur_sum += sat[i];
		if (cur_sum <= 0)
			break;
		mx += cur_sum;
	}
	return mx;
}