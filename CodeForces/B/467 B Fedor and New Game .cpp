#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// m + 1 players numberd from  to m + 1
	// n types of soldiers numbered from 0 to n-1

	// input: n, m, k

	int n, m, k, count = 0, fedor, difference_count;

	cin >> n >> m >> k;
	vector<int> x(m + 1);
	for (int &it : x)
		cin >> it;

	fedor = x[m];

	for (int i = 0; i < m; ++i)
	{
		difference_count = 0;

		for (int mask = 0; mask < n && difference_count <= k; ++mask)
		{
			if (((x[i] >> mask) & 1) != ((fedor >> mask) & 1))
				++difference_count;
		}
		if (difference_count <= k)
			++count;
	}
	cout << count;

	return 0;
}