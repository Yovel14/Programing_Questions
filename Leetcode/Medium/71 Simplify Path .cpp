// Time : O(n)
// Space : O(n + n) = O(n) // two stacks
string simplifyPath(string path)
{
	if (path.size() == 1)
		return "/";

	stack<string> st;
	string s = "";
	int n = path.size();
	for (int i = 1; i < n; i++)
	{
		while (i < n && path[i] != '/')
			s.push_back(path[i++]);
		if (s == "..")
		{
			if (!st.empty())
				st.pop();
		}
		else if (s != "" && s != ".")
			st.push(s);
		s = "";
	}

	if (st.empty())
		return "/";

	stack<string> ns;
	while (!st.empty()) // reversing the stack to build the string in O(n) instead of O(n^2)
	{
		ns.push(st.top());
		st.pop();
	}

	s = "";
	while (!ns.empty())
	{
		s.append("/" + ns.top());
		ns.pop();
	}
	return s;
}