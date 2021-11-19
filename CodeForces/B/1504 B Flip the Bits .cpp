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
	string a, b;
	cin >> n >> a >> b;
	a.push_back('0');
	b.push_back('0');

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '1')
			count++;
		else
			count--;

		if ((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && count != 0)
		{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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