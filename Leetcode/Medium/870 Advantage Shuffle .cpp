// three pointers solution
// Time : O(nlog2(n))
// Space : O(n)
vector<int> advantageCount(vector<int> &a, vector<int> &b)
{
	int n = a.size();
	sort(a.begin(), a.end());
	vector<pair<int, int>> sb(n);
	for (int i = 0; i < n; i++)
		sb[i] = make_pair(b[i], i);
	sort(sb.begin(), sb.end());

	int m = n - 1;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > sb[j].first)
			b[sb[j++].second] = a[i];
		else
			b[sb[m--].second] = a[i];
	}

	return b;
}

// Time : O(nlog2(n))
// Space : O(n)
vector<int> advantageCount(vector<int> &a, vector<int> &b)
{
	// the best permutaion is the one where we choose the first bigest number for each index i in B
	int n = a.size();
	multiset<int> ms;
	for (int &e : a)
		ms.insert(e);

	for (int i = 0; i < n; i++)
	{
		multiset<int>::iterator it = ms.upper_bound(b[i]);
		if (it == ms.end())
		{
			a[i] = *ms.begin();
			ms.erase(ms.begin());
		}
		else
		{
			a[i] = *it;
			ms.erase(it);
		}
	}

	return a;
}