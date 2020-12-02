#include <iostream>
#include <vector>
#include <algorithm>

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

	// n line segment
	// the i th line has length a[i]
	// use exactly 3 line segment to create a non degenerate triagle

	// for a non degenerate triangle with a,b,c sides a <= b <= c
	// if a,b,c don't form triangle  than adding or removing to a or c will not make create a triangle
	int n;
	cin >> n;
	//n = 5;
	vector<int> v(n);
	//v = {1, 5, 3, 2, 4};
	for (int &it : v)
		cin >> it;

	bool worked = false;
	sort(v.begin(), v.end());
	for (int i = 2; i < n; ++i)
	{

		if (v[i - 1] + v[i - 2] > v[i]) //if the sum of the small one greater than the big than sum of the big with either will be larger than the other
		{
			worked = true;
			break;
		}
	}

	if (worked)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}