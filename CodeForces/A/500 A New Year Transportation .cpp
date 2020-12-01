#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// n cells numbered from 1 to n
	int n, t;
	cin >> n >> t;

	vector<int> v(n - 1);
	for (int &it : v)
		cin >> it;

	--n;
	--t; // converting it to a zero based indexing

	int i = 0;
	while (i < t && i < n)
	{
		i += v[i];
	}

	if (i == t)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}