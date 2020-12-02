#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &it : a)
		cin >> it;
	vector<int> out;
	unordered_set<int> s;
	for (int i = n - 1; i >= 0; --i)
	{
		if (s.count(a[i]) == 0)
		{
			out.push_back(a[i]);
			s.insert(a[i]);
		}
	}
	cout << out.size() << '\n';
	for (int i = out.size() - 1; i >= 0; --i)
		cout << out[i] << ' ';

	return 0;
}