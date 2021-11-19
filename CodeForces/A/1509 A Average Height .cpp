#include <iostream>
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

void inline solve()
{
	int n;
	cin >> n;
	stack<int> even;
	stack<int> odd;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp & 1)
			odd.push(tmp);
		else
			even.push(tmp);
	}

	while (!odd.empty())
	{
		cout << odd.top() << ' ';
		odd.pop();
	}
	while (!even.empty())
	{
		cout << even.top() << ' ';
		even.pop();
	}
	cout << '\n';
}

main()
{
	FastIO;

	preCampute();

	int ctc = 1;
	//cout << "\n\n";
	cin >> ctc;
	while (ctc--)
	{
		solve();
	}
}