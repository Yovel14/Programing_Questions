#include <iostream>
#include <vector>

using namespace std;

int Max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return a;
	if (b >= a && b >= c)
		return b;

	return c;
}

int Min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;

	return c;
}

int main() // using sorted set would be faster O(nlog2(n))
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// n balls
	// i th ball hs size t

	// each freind gets a different size ball
	// no two friesnds can get balls of size thant differ by more than 2

	// since n < 50 I can do O(n^3)
	int n;
	cin >> n;

	vector<int> v(n);
	for (int &it : v)
		cin >> it;

	bool found = false;

	for (int a = 0; a < n; ++a)
	{
		for (int b = a + 1; b < n; ++b)
		{
			if (v[a] == v[b] || v[a] - 2 > v[b] || v[b] - 2 > v[a])
				continue;
			for (int c = b + 1; c < n; ++c)
			{
				int temp1 = Max(v[a], v[b], v[c]);
				int temp2 = Min(v[a], v[b], v[c]);
				int temp3 = temp1 - temp2;
				if ((v[a] != v[b] && v[a] != v[c] && v[b] != v[c]) && Max(v[a], v[b], v[c]) - 2 == Min(v[a], v[b], v[c])) //has to be 2
				{
					found = true;
					break;
				}
			}
			if (found)
				break;
		}
		if (found)
			break;
	}

	if (found)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}