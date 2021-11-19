// Time : O(n)
// Space : O(n)
bool validateStackSequences(vector<int> &pushed, vector<int> &poped)
{
	if (pushed.size() != poped.size())
		return false;
	if (pushed.size() == 0)
		return true;

	stack<int> s;
	s.push(pushed[0]);
	int i = 1, j = 0;
	int n = pushed.size();
	while (i < n || j < n)
	{
		if (!s.empty() && poped[j] == s.top())
		{
			j++;
			s.pop();
		}
		else
		{
			if (i < n)
				s.push(pushed[i++]);
			else
				return false;
		}
	}
	return true;
}

// Time : O(n)
// Space : O(1)
bool validateStackSequences(vector<int> &pushed, vector<int> &poped)
{
	if (pushed.size() != poped.size())
		return false;
	if (pushed.size() == 0)
		return true;

	int i = 0, j = 0, k = -1;
	int n = pushed.size();
	for (; i < n && j < n; i++)
	{
		pushed[++k] = pushed[i];
		while (k != -1 && pushed[k] == poped[j])
		{
			k--;
			j++;
		}
	}

	return k == -1 && i == n && j == n;
}