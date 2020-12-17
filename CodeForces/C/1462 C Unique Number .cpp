#include <iostream>
#include <vector>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void Possible()
{
	int x;
	cin>>x;
	vector<int> digits;

	int sum = 0;
	int last_digit = 9;

	while(last_digit>0 && sum<x)
	{// the min is for checking if there is a smaller number to complete
		digits.push_back(min(x-sum,last_digit));
		sum+=min(x-sum,last_digit);
		--last_digit;
	}

	if(sum<x)// if x is bigger than the sum of 1->9 inclusive
	{
		cout<<-1<<'\n';
		return;
	}
	for(int i = digits.size()-1;i>=0;--i)
		cout<<digits[i];
	cout<<'\n';
}

int main()
{
	FastIO;

	// given x find smallest psitive number witch sum of digits equal to x (all digits are distinct)
	// idea to get the smallest number go from end and and add the greatest not used digit

	int t;
	cin>>t;
	while(t--)
	{
		Possible();
	}

	return 0;
}