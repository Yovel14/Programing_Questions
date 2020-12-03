#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 1 to n are written on the board
	// in one operation can earase any two a adn b from the board and write one integer (a + b) / 2 round up
	// perform each operatoin n-1 times to get the smallest possible number

	//Idea to get the smallest number take the two biggest numbers and average them thus the average operaiton will bring up each numbers by the smallest amount

	// solution without using a vector with 1 throw n numbers (there is a better solution in the problem tutorial)
	int t, n;
	double average = 0;
	cin >> t;

	while (t--)
	{

		cin >> n;
		vector<int> re;
		average = n;
		for (double i = n - 1; i >= 1; --i)
		{

			re.push_back(average);
			re.push_back(i);
			average = ceil((average + i) / 2);
		}

		// output
		cout << average << '\n';
		for (int i = 0; i < re.size() - 1; i += 2)
			cout << re[i] << ' ' << re[i + 1] << '\n';
	}

	return 0;
}
/* // with vector
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 1 to n are written on the board
	// in one operation can earase any two a adn b from the board and write one integer (a + b) / 2 round up
	// perform each operatoin n-1 times to get the smallest possible number

	//Idea to get the smallest number take the two biggest numbers and average them thus the average operaiton will bring up each numbers by the smallest amount
	int t, n;
	cin >> t;

	while (t--)
	{

		cin >> n;
		vector<double> v(n);
		vector<int> re;

		for (double i = 0; i < n; ++i)
			v[i] = i + 1;

		for (int i = n - 1; i > 0; --i)
		{
			re.push_back(v[i - 1]);
			re.push_back(v[i]);
			v[i - 1] = ceil((v[i - 1] + v[i]) / 2);
		}

		// output
		cout << v[0] << '\n';
		for (int i = 0; i < re.size() - 1; i += 2)
			cout << re[i] << ' ' << re[i + 1] << '\n';
	}

	return 0;
}
*/