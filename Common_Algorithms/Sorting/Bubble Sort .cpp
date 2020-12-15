#include<vector>
using namespace std;

void Bubble_Sort(vector<int> &v) // O(n^2) because doing n
{	
	int n = v.size();
	bool isSorted = false;
	int temp;
	while(!isSorted)// loop will be at most O(n)
	{
		isSorted = true;
		for(int i = 0;i<n-1;++i)// loop is done O(n)
		{
			if(v[i]>v[i+1])
			{// swap v[i] ,v[i+1]
				isSorted = false;
				temp = v[i+1];
				v[i+1] = v[i];
				v[i] = temp;
			}
		}
	}
	// v is a refrence no need to return it
}