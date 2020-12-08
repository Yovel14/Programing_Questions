#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// n columns
	// i th column has l[i] soldiers who start with l and r[i] who start with right
	// beuaty = abs(L - R)

	// sum all values and try chaging all to see change

	int n, suml = 0, sumr = 0, mx = 0, mx_index = 0;
	bool switched = false;
	cin >> n;
	vector<pair<int, int>> pairs(n);

	for (auto &it : pairs)
	{
		cin >> it.first;
		suml += it.first;
		cin >> it.second;
		sumr += it.second;
	}
	mx = abs(suml - sumr);
	for (int i = 0; i < n; ++i)
	{
		if (mx < abs((suml - pairs[i].first + pairs[i].second) - (sumr - pairs[i].second + pairs[i].first)))
		{

			mx_index = i + 1;
			mx = abs((suml - pairs[i].first + pairs[i].second) - (sumr - pairs[i].second + pairs[i].first));
		}
	}
	cout << mx_index;

	return 0;
}