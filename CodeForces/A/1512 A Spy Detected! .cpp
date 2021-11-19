#include <iostream>
#include <vector>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

void inline solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int i = 1;
	for (; i + 1 < n && v[i] == v[i - 1] && v[i] == v[i + 1]; i++)
	{
	}

	if (v[i] != v[i + 1] && v[i] != v[i - 1])
		cout << (i + 1) << '\n';
	else if (v[i - 1] != v[i])
		cout << (i) << '\n';
	else
		cout << (i + 2) << '\n';
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