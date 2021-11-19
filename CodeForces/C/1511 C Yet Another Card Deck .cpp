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

using ll = long long;
using namespace std;

void inline preCampute() {}

void inline solve()
{
	int n, q;
	cin >> n >> q;
	int pos[51];
	memset(pos, -1, sizeof(pos));
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if (pos[tmp] == -1)
			pos[tmp] = i;
	}

	while (q--)
	{
		int color;
		cin >> color;
		int colorPos = pos[color];
		cout << (colorPos + 1) << ' ';
		for (int i = 0; i < 51; i++)
			if (pos[i] < colorPos)
				pos[i]++;
		pos[color] = 0;
	}
	cout << '\n';
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