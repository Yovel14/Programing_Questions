#include<vector>
using namespace std;

void Insertion_Sort(vector<int> &v)// O(n^2)
{
	int n = v.size();
	int val;
	int j;
	for(int i = 1; i<n;++i)
	{
		val = v[i];
		for(j = i-1; j>=0 && v[j]>val;--j)
		{
			v[j+1] = v[j];
		}
		v[j+1] = val;
	}
}