#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstddef>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <utility>

#define FastIO                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

using ll = long long;
using namespace std;

main()
{
	FastIO;

	int H, W;
	cin >> H >> W;
	string c[H];
	for (int h = 0; h < H; h++)
		cin >> c[h];

	int h = 0, w = 0;
	int count = c[h][w] == '*';
	while (h < H && w < W)
	{
		if (w + 1 < W && c[h][w + 1] == '*')
		{
			w++;
			count++;
		}
		else if (h + 1 < H && c[h + 1][w] == '*')
		{
			h++;
			count++;
		}
		else if (w + 1 < W)
			w++;
		else
			h++;
	}

	cout << count;
}