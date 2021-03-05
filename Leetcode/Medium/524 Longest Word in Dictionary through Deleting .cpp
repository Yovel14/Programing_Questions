// Time : O(m*x*log2(x*m) + n*m*x) where m is the length of dic and n is the length of s and x is the average length of string in dic
// Space : O(mx_length + m*x) where mx_length is the maximum length of string in dic
// sort and compare until found the first and because of the sorting it's the first one
static bool sort_by_size(string &a, string &b)
{
	return a.size() > b.size() || (a.size() == b.size() && a < b);
}
string findLongestWord(string &s, vector<string> &dic)
{
	sort(dic.begin(), dic.end(), sort_by_size);
	int p;
	int n = s.size();
	for (string &str : dic)
	{
		if (str.size() > n)
			continue;
		p = 0;
		for (int i = 0; i < n; i++)
			if (str[p] == s[i])
				p++;
		if (p == str.size())
			return str;
	}
	return "";
}

// without sorting
// Time : O(n*m*x) where m is the length of dic and n is the length of s and x is the average length of string in dic
// Space : O(mx_length) where mx_length is the maximum length of string in dic
string findLongestWord(string &s, vector<string> &dic)
{
	int p;
	int n = s.size();
	int m = dic.size();
	int ans = -1;

	for (int j = 0; j < m; j++)
	{
		if (dic[j].size() > s.size())
			continue;
		p = 0;
		for (int i = 0; i < n; i++)
			if (dic[j][p] == s[i])
				p++;
		if (p == dic[j].size())
		{
			if (ans == -1)
				ans = j;
			else if (dic[ans].size() < dic[j].size() || (dic[ans].size() == dic[j].size() && dic[ans] > dic[j]))
				ans = j;
		}
	}

	return ans == -1 ? "" : dic[ans];
}

// TLE
// Trie
// Time : O(n*m+ k) n is the length of dic and m the the max length in dic k is the length of s
// Space : O(m*m)
class Trie
{
public:
	Trie *c[27] = {0};
	bool end = false;
	Trie()
	{
		for (int i = 0; i < 27; i++)
			c[i] = nullptr;
	}
};
void build_Trie(string &s, Trie *b)
{
	int n = s.size();
	char k;
	for (int i = 0; i < n; i++)
	{
		k = s[i] - 'a';
		if (!b->c[k])
			b->c[k] = new Trie(); //"apple", "ale", "monkey", "plea"
		b = b->c[k];
	}
	b->end = true;
}
void find_longest(string &s, int i, Trie *b, string pa, string &ans)
{
	if (b)
	{
		if (b->end)
			if (pa.size() > ans.size() || (pa.size() == ans.size() && pa < ans))
				ans = pa;
	}
	else
		return;

	for (; i < s.size(); i++)
		if (b->c[s[i] - 'a'])
			find_longest(s, i + 1, b->c[s[i] - 'a'], pa + s[i], ans);
}
class Solution
{
public:
	string findLongestWord(string &s, vector<string> &dictionary)
	{
		// build Trie tree
		Trie *b = new Trie();
		for (string &str : dictionary)
			build_Trie(str, b);

		// find the longeset string
		string ans = "";
		find_longest(s, 0, b, "", ans);
		return ans;
	}
};