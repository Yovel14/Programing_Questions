#include<vector>
using namespace std;

void Selection_Sort(vector<int> &v)// O(n^2)
{
	int n = v.size();
	int min_index, temp;
	for(int i = 0; i<n;++i)
	{
		min_index = i; 
		for(int j = i + 1;j<n;++j)
			if(v[j]<v[min_index])
				min_index = j;
		//swap v[i], v[min_index]
		temp = v[min_index];
		v[min_index] = v[i];
		v[i] = temp;
	}
}