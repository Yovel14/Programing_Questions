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
}

/* //uses more memory but does the same thing just with the with updating the sum on the vector itself
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// n dormitories nimbered from 1 to n
	// a[i] rooms in i th dermitory
	int n, m;
	long long int last_value;
	cin >> n >> m;
	vector<long long int> a(n);
	vector<long long int> b(m);
	cinVec(a);
	cinVec(b);
	for (int i = 1; i < n; i++)
		a[i] += a[i - 1];
	int i = 0;
	int j = 0;
	while (i < n && j < m)
	{
		if (b[j] <= a[i])
		{
			if (i == 0)
				last_value = 0;
			else
				last_value = a[i - 1];
			cout << i + 1 << ' ' << b[j] - last_value << '\n';
			++j;
		}
		else
			i++;
	}

	return 0;
}
*/