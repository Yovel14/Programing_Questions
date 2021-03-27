#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;
void solve()
{
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		m[tmp]++;
	}

	priority_queue<int> q;
	for (auto a : m)
		q.push(a.second);

	while (q.size() > 1)
	{
		int cnt1 = q.top();
		q.pop();
		int cnt2 = q.top();
		q.pop();

		cnt1--;
		cnt2--;
		n -= 2;
		if (cnt1)
			q.push(cnt1);
		if (cnt2)
			q.push(cnt2);
	}

	cout << n << '\n';
}

main()
{
	FastIO;

	int ctc;
	ctc = 1;
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}