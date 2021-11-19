// Time : O(n*k)
// Space : O(n)
string removeDuplicates(string str, int k)
{
	queue<char> q;
	int n = str.size();
	for (int i = 0; i < n; i++)
		q.push(str[i]);

	bool possible = true;
	while (possible)
	{
		possible = false;
		int length = q.size();

		while (length--)
		{
			char tmp = q.front();
			cout << tmp << ' ';
			q.pop();
			q.push(tmp);
		}
		cout << '\n';
		length = q.size();

		char c = 'A';
		int count = 0;
		while (length--)
		{
			if (count == k)
			{
				possible = true;
				count = 0;
			}
			if (c == q.front())
			{
				q.pop();
				count++;
			}
			else
			{
				if (count != 0)
					while (count--)
						q.push(c);
				c = q.front();
				q.pop();
				count = 1;
			}
		}

		if (count == k)
		{
			possible = true;
			count = 0;
		}
		if (count != 0)
			while (count--)
				q.push(c);
	}

	string ans;
	ans.resize(q.size());
	ans.resize(0);

	while (!q.empty())
	{
		ans.push_back(q.front());
		q.pop();
	}

	return ans;
}

// a bit improved on space and Time
// Time : O(n*k)
// Space : O(n)
string inline removeDuplicates(string &str, int k)
{
	queue<pair<char, int>> q;
	int n = str.size();
	char c = str[0];
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (c == str[i])
			cnt++;
		else
		{
			cnt %= k;
			if (cnt != 0)
				q.push({c, cnt});
			c = str[i];
			cnt = 1;
		}
	}
	if (cnt)
		q.push({c, cnt});

	bool possible = true;
	while (possible)
	{
		possible = false;
		int length = q.size();
		while (length--)
		{
			pair<char, int> tmp = q.front();
			q.pop();
			while (length && q.front().first == tmp.first)
			{
				tmp.second += q.front().second;
				q.pop();
				length--;
			}
			if (tmp.second >= k)
				possible = true;
			tmp.second %= k;
			if (tmp.second)
				q.push(tmp);
		}
	}

	string ans = "";
	ans.resize(q.size());
	ans.resize(0);
	while (!q.empty())
	{
		pair<char, int> tmp = q.front();
		q.pop();
		while (tmp.second--)
			ans.push_back(tmp.first);
	}
	return ans;
}