#include<iostream>
#include<vector>
#include<unordered_set>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
	FastIO;
	// find from the back the amount of none repeating number and set them to a vector

	int n,m, distinct_int_count = 0,l;
	cin>>n>>m;

	vector<int> input(n);
	vector<int>  repeat_count(n);
	unordered_set<int> exist;
	
	for(int &it: input) cin>>it;
	
	for(int i = n-1;i>=0;--i)
	{
		if(exist.find(input[i])!=exist.end())
		{
			repeat_count[i] = distinct_int_count;
		}
		else
		{
			++distinct_int_count;
			repeat_count[i] = distinct_int_count;
			exist.insert(input[i]);
		}
	}

	while(m--)
	{
		cin>>l;
		cout<<repeat_count[l-1]<<'\n';
	}

	return 0;
}