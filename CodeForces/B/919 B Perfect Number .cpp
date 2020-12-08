#include <iostream>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int sum_of_digits(int num)
{
	int sum = 0;
	while(num)
	{
		sum+=num%10;
		num/=10;
	}
	return sum;
}
void find(){
	int k;
	cin>>k;
	int i = 18;
	int count = 0;
	while(i++){
		if(sum_of_digits(i) == 10)
		{
			++count;
			if(count == k)
			{
				cout<<i;
				return;
			}
		}
	}
}
int main()
{
	FastIO;

	// 1 - 19
	// I will try brute force

	find();

	return 0;
}