#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <utility>
#include <queue>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

// Special types
template <typename T>
using vc = std::vector<T>;
template <class T>
using vc = std::vector<T>;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using ll = long long;

using namespace std;

const int MOD = 1000000007;

void inline preCampute() {}

void inline solve()
{
	int n;
	string str;
	cin >> n >> str;
	queue<int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size() != 1)
		for (int i = 0; i < str.size() && q.size() != 1; i++)
		{
			if (str[i] == 'x')
			{
				q.push(q.front());
				q.pop();
			}
			else
				q.pop();
		}
	cout << q.front();
}

main()
{
	FastIO;

	preCampute();

	int ctc = 1;
	//cout << "\n\n";
	//cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}