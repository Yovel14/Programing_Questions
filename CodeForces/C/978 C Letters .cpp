#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void cinVec(vector<T> &v)
{
	for (T &it : v)
		cin >> it;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// n dormitories nimbered from 1 to n
	// a[i] rooms in i th dermitory
	//add to sum when continueing on vector a and check with current one if the b[j] is smaller than sum

	int n, m;
	long long int sum = 0, last_value = 0;
	cin >> n >> m;
	vector<long long int> a(n);
	vector<long long int> b(m);
	cinVec(a);
	cinVec(b);

	int i = 0;
	int j = 0;
	while (i < n && j < m)
	{
		long long int temp1 = a[i];
		long long int temp2 = b[j];

		if (b[j] <= sum + a[i])
		{
			cout << i + 1 << ' ' << b[j] - sum << '\n';
			++j;
		}
		else
		{
			sum += a[i];
			++i;
		}
	}

	return 0;