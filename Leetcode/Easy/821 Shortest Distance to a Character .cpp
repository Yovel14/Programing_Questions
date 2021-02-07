// Time : O(n * k) where n is the length of s and k is the number appearence for c
// Space : O(n)
vector<int> shortestToChar(string s, char c)
{
	int n = s.size();
	vector<int> d(n, INT_MAX);

	for (int i = 0; i < n; i++)
		if (s[i] == c)
			for (int j = 0; j < n; j++)
				d[j] = min(d[j], abs(i - j));

	return d;
}

// Time : O(n)
// Space : O(n)
vector<int> shortestToChar(string s, char c)
{
	int n = s.size();
	vector<int> d(n);

	int c_i = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == c)
			c_i = i;
		d[i] = abs(c_i - i);
	}

	c_i = INT_MAX;
	for (int i = n - 1; i != -1; i--)
	{
		if (s[i] == c)
			c_i = i;
		d[i] = min(d[i], c_i - i);
	}
	return d;
}

// Time : O(n) where n is the length of
// Space : O(n)
vector<int> shortestToChar(string s, char c)
{
	int n = s.size();
	vector<int> app(n);
	vector<int> d(n);
	int p = 0; // the actual size of app

	for (int i = 0; i < n; i++)
		if (s[i] == c)
			app[p++] = i;
	if (p < n)
		app[p++] = INT_MAX;

	int app_i = 0;
	int i = 0;
	for (; i <= app[app_i]; i++)
		d[i] = app[app_i] - i;

	for (; i < n; i++)
	{
		if (i > app[app_i + 1])
			app_i++;
		d[i] = min(abs(app[app_i] - i), abs(app[app_i + 1] - i));
	}

	return d;
}