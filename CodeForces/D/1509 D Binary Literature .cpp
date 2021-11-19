#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <utility>
#include <stack>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

#define v(T) vector<T>
using ll = long long;
using namespace std;

const int MOD = 1000000007;

void inline preCampute() {}

void f(string &ans, string &s, int &i, int &n2)
{
	while (i < n2)
		ans.push_back(s[i++]);
}

void inline solve()
{
	vector<string> s0, s1;
	int n;
	cin >> n;
	int n2 = n * 2;
	string a, b, c;
	cin >> a >> b >> c;

	string ans = "";
	ans.resize(3 * n);
	ans.resize(0);
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n2 && j < n2 && k < n2)
	{
		if (a[i] == b[j])
		{
			ans.push_back(a[i]);
			if (c[k] == a[i])
				k++;
			i++;
			j++;
		}
		else if (a[i] == c[k])
		{
			ans.push_back(a[i]);
			if (a[i] == b[j])
				j++;
			i++;
			k++;
		}
		else // b[j] == c[k]
		{
			ans.push_back(b[j]);
			if (b[j] == a[i])
				i++;
			j++;
			k++;
		}
	}

	if (i == n2)
	{
		if (j > k)
			f(ans, b, j, n2);
		else
			f(ans, c, k, n2);
	}
	else if (j == n2)
	{
		if (i > k)
			f(ans, a, i, n2);
		else
			f(ans, c, k, n2);
	}
	else
	{
		if (i > j)
			f(ans, a, i, n2);
		else
			f(ans, b, j, n2);
	}

	assert(ans != "");
	cout << ans << "\n";
}

main()
{
	FastIO;

	preCampute();

	int ctc = 1;
	cout << "\n\n";
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}