// Time : O(n)
// Space : O(1)
bool isIdealPermutation(vector<int> &a)
{
	int n = a.size();
	if (n < 2)
		return true;
	int mx = INT_MIN;
	bool last = false;
	for (int i = 0; i < n; i++)
	{

		if (!last && mx > a[i])
			return false;
		if (mx < a[i])
		{
			if (i != n - 1)
			{
				if (a[i + 1] < mx)
					return false;
				mx = a[i];
				last = true;
			}
		}
		else
			last = false;
	}
	return true;
}

// Time : O(n)
// Space : O(1)
bool isIdealPermutation(vector<int> &a)
{
	int n = a.size();
	for (int i = 0; i < n; i++)
		if (abs(a[i] - i) > 1)
			return false;
	return true;
}