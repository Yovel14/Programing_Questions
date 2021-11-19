// Time : O(n*(n-m) *(m+m)) = O(n*m*(n-m))
// Space : O(l) where l is the number of moves
bool possibleStamp(string &stamp, string &target, int index) // O(m)
{
	bool onlyQ = true;
	for (int j = 0; j < stamp.size(); j++, index++) // I know index will be smaller than target.size
	{
		if (target[index] != '?')
		{
			onlyQ = false;
			if (target[index] != stamp[j])
				return false;
		}
	}
	return !onlyQ;
}

vector<int> inline movesToStamp(string stamp, string target)
{
	int n = target.size();
	int m = stamp.size();
	int remain = n;

	vector<int> ans;
	while (remain) // O(n)
	{
		bool flag = false;
		for (int i = 0; i < n - m + 1; i++) //O(n-m)
			if (possibleStamp(stamp, target, i))
			{
				ans.push_back(i);
				flag = true;
				for (int j = 0; j < m; j++) //O(m)
					if (target[i + j] != '?')
					{
						target[i + j] = '?';
						remain--;
					}
			}
		if (!flag)
			return {};
	}

	reverse(ans.begin(), ans.end());
	return ans;
}