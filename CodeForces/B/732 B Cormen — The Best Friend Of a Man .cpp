#include <iostream>
#include <vector>

using namespace std;

int Min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;

	return c;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// at least k walks for any 2 consecutive days
	//

	int n, k, count = 0;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	for (int i = 1; i < n; ++i)
	{
		if (v[i - 1] + v[i] < k)
		{
			count += k - (v[i - 1] + v[i]);
			v[i] = k - v[i - 1];
			//
		}
	}

	cout << count << '\n';
	for (int &it : v)
		cout << it << ' ';
	cout << '\n';

	return 0;
}