void combination(int n, int k, int index_loop, int index_current, vector<vector<int>> &com, vector<int> &current)
{
	if (index_current == k)
		com.push_back(current);
	else
		for (; index_loop <= n && (n - index_loop + 1) >= (k - index_current); index_loop++) // && (n - index_loop + 1) >= (k - index_current)    is not necessary but it shortens the time when it is not possible to complete the vector with the remaining values
		{
			current[index_current] = index_loop;
			combination(n, k, index_loop + 1, index_current + 1, com, current);
		}
}
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> com;
	vector<int> v(k);
	combination(n, k, 1, 0, com, v);
	return com;
}