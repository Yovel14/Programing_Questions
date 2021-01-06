// iteration
int findKthPositive(vector<int> &a, int k)
{
	int num = 1;
	int i = 0;
	int missing;
	int n = a.size();

	while (i < n && k)
	{
		if (num != a[i])
		{
			missing = num;
			num++;
			k--;
		}
		else
		{
			num++;
			i++;
		}
	}
	if (k)
		return a[n - 1] + k;
	return missing;
}

// binary search 1
int findKthPositive(vector<int> a, int k)
{
	int l = 0, h = a.size() - 1;
	int m;
	while (l < h)
	{
		m = l + ((h - l) >> 1);
		if (a[m] - m - 1 < k)
			l = m + 1;
		else
			h = m - 1;
	}
	int missing = a[l] - l - 1;
	if (missing >= k)
		return a[l] - (missing - k + 1);
	return a[l] - (k - missing);
}

// binary search 2
int findKthPositive(vector<int> a, int k)
{
	int l = 0, h = a.size();
	int m;
	while (l < h)
	{
		m = l + ((h - l) >> 1);
		if (a[m] - m - 1 < k)
			l = m + 1;
		else
			h = m;
	}
	return l + k;
}