// Time : O(n^2)
// Space : O(n)
vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
	int n = mat.size();
	int m = mat[0].size();
	vector<pair<int, int>> v(n); // 1 {count1 , index in mat}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j < m; j++)
			if (mat[i][j])
				count++;
		v[i].first = count;
		v[i].second = i;
	}

	sort(v.begin(), v.end());

	vector<int> ans(k);
	for (int i = 0; i < k; i++)
		ans[i] = v[i].second;

	return ans;
}

// Time : O(n * log2(n))
// Space : O(n)
// Binary search for finding the amount of soldiers
int upper_bound(vector<int> &v)
{
	int l = 0;
	int h = v.size() - 1;
	if (h != 0)
	{
		if (v[0] == 0)
			return -1;
		if (v[h] == 1)
			return h;
	}

	int mid;
	while (l < h)
	{
		mid = l + ((h - l) >> 1) + 1;
		if (v[mid] == 1)
			l = mid;
		else
			h = mid - 1;
	}
	return l;
}
vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
	int n = mat.size();
	vector<pair<int, int>> v(n); // 1 {count1 , index in mat}

	for (int i = 0; i < n; i++)
	{
		v[i].first = upper_bound(mat[i]) + 1;

		v[i].second = i;
	}

	sort(v.begin(), v.end());

	vector<int> ans(k);
	for (int i = 0; i < k; i++)
		ans[i] = v[i].second;

	return ans;
}

// instead of sorting using a ordered set or a priority queue is also possible