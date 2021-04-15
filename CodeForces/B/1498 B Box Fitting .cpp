#include <iostream>
#include <cmath>
#include <set>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

// solution 1 : multiset
// Time : O(n)
// Space : O(n)
void solve()
{
	multiset<int> ms;
	int n, w;
	cin >> n >> w;

	while (n--)
	{
		int tmp;
		cin >> tmp;
		ms.insert(tmp);
	}

	int count = 0;
	int widthLeft;
	while (!ms.empty())
	{
		widthLeft = w;
		multiset<int>::iterator it = ms.upper_bound(widthLeft);
		while (it != ms.begin())
		{
			it--;
			widthLeft -= (*it);
			ms.erase(it);
			it = ms.upper_bound(widthLeft);
		}
		count++;
	}
	cout << count << '\n';
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

// Solution 2: reling on the fact that there are only 20 numbers of a power of 2 in the range
// Time : O(n*20) = O(n)
// Space : O(20) = O(1)
void solve()
{
	int n, w;
	cin >> n >> w;

	int widths[20] = {}; // highst possible power of 2 from to the constrains
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		widths[int(log2(tmp))]++;
	}

	int count = 0;
	int widthLeft = 0;
	while (n)
	{
		widthLeft = w;
		for (int i = 19; i != -1; i--)
		{
			if (widths[i])
			{
				int tmp = (1 << (i));
				while (widthLeft >= tmp && widths[i])
				{
					widths[i]--;
					widthLeft -= (1 << (i));
					n--; // to know when I have no more re
				}
			}
		}
		count++;
	}

	cout << count << '\n';
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