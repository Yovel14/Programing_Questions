

//#pragma GCC optimization("02")
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <utility>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

#define v(T) vector<T>

/*
    #define v(T) vector<T>
    #define vi vector<int>;
    #define vvi vector<vector<int>> > ;
    #define pii pair<int, int>;
    #define vpii vector<pair<int, int>>;
    */
using ll = long long;
using namespace std;

const int MOD = 1000000007;

int powers[11];
int sum[2048];
void inline preCampute()
{
	int a = 1;
	for (int i = 0; i < 11; i++, a *= 4)
		powers[i] = a;

	int p = 0;
	int limit = (1 << 10) + 1;
	for (int mask = 0; mask < limit; mask++)
	{
		int s = 0;
		for (int i = 0; i < 11; i++)
			if ((mask >> i) & 1)
				s += powers[i];
		sum[p++] = s;
	}

	//for (int i = 0; i < p; i++)
	//	cout << sum[i] << '\n';
}

void inline solve()
{
	int n;
	cin >> n;
	cout << (*upper_bound(sum, sum + 513, n - 1)) << '\n';
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