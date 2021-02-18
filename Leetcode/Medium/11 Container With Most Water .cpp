// Time : O(n)
// Space : O(1)
int maxArea(vector<int> &height)
{
	int mx = 0;
	int l = 0, r = height.size() - 1;

	while (l < r)
	{
		if (height[r] > height[l])
		{
			mx = max(mx, height[l] * (r - l));
			l++;
		}
		else
		{
			mx = max(mx, height[r] * (r - l));
			r--;
		}
	}

	return mx;
}

// Time : O(n^2)
// Space : O(1)
int maxArea(vector<int> &height) // O(n^2)
{
	int mx = 0;
	int mn_height;
	int n = height.size();
	int temp;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			temp = min(height[i], height[j]) * (j - i);
			if (temp > mx)
				mx = temp;
		}
	}

	return mx;
}