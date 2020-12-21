int maxArea(vector<int> &height) // O(n)
{
	int mx = 0;
	int r = 0, l = height.size() - 1;
	int temp;
	while (r < l)
	{
		if (height[r] >= height[l])
		{
			temp = height[l] * (l - r);
			l--;
		}
		else
		{
			temp = height[r] * (l - r);
			r++;
		}
		if (temp > mx)
			mx = temp;
	}

	return mx;
}

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