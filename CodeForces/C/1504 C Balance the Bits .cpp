#include <iostream>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	if (s[0] == '0' || s[n - 1] == '0')
	{
		cout << "NO\n";
		return;
	}

	int count = 0;
	for (int i = 1; i < n; i++)
		count += s[i] == '1';
	if (count % 2 == 0)
	{
		cout << "NO\n";
		return;
	}

	string a, b;
	a.resize(n);
	a.resize(0);
	b.resize(n);
	b.resize(0);

	bool flip = true;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			a.push_back(2 * k < count ? '(' : ')');
			b.push_back(a.back());
			k++;
		}
		else
		{
			a.push_back(flip ? '(' : ')');
			b.push_back(flip ? ')' : '(');
			flip = !flip;
		}
	}
	cout << "YES\n";
	cout << a << '\n'
		 << b << '\n';
}

main()
{
	FastIO;

	int ctc = 1;
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}