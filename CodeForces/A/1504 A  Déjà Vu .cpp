#include <iostream>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

bool pal(string str)
{
	int s = 0, e = str.size() - 1;
	while (s < e)
		if (str[s++] != str[e--])
			return false;
	return true;
}
void solve()
{
	string str;
	cin >> str;

	if (!pal(str + 'a'))
	{
		cout << "YES\n";
		cout << str + 'a' << '\n';
	}
	else if (!pal('a' + str))
	{
		cout << "YES\n";
		cout << 'a' << str << '\n';
	}
	else
		cout << "NO\n";
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