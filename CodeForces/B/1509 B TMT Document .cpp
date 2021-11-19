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
	string str;
	cin >> n >> str;

	int countT = 0, countM = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'T')
			countT++;
		else
			countM++;
		if (countM > countT)
		{
			cout << "NO\n";
			return;
		}
	}

	countT = 0, countM = 0;
	for (int i = n - 1; i > -1; i--)
	{
		if (str[i] == 'T')
			countT++;
		else
			countM++;
		if (countM > countT)
		{
			cout << "NO\n";
			return;
		}
	}

	if (countM * 2 != countT)
		cout << "NO\n";
	else
		cout << "YES\n";
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