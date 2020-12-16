#include<vector>
using namespace std;

void Choose_Pivot(vector<int> &v,int &l, int &r)// sets pivot as the the value on r index. the pivot will be the value which is the middle between l,r,(r+l)/2
{
	if(l!=r)
	{
		int mid = l+(r-l)/2; // mid index (the same as (r+l)/2 just this prevents integer overflow)
		if((v[l]>v[r]&& v[l]<v[mid]) || (v[l]<v[r]&& v[l]>v[mid]))
			swap(v[l],v[r]);
		else if((v[mid]>v[r] && v[mid]<v[l]) || (v[mid]<v[r] && v[mid]>v[l]))
				swap(v[mid],v[r]);
		// v[r] is the middle value
	}
}

void Quick_Sort(vector<int> &v,int l = 0,int r = -2)// O(n^2) worst case // O(nlog(n)) average case
{
	if(r == -2) r = v.size()-1;
	
	if(l<r){

		Choose_Pivot(v,l,r);// just to help it get closer to O(nlog(n))

		int i = l;
		for(int j = l;j<r;++j)
		{
			if(v[j]<=v[r])
			{
				swap(v[i],v[j]);
				++i;
			}
		}
		swap(v[i],v[r]);

		Quick_Sort(v,l,i-1);
		Quick_Sort(v,i+1,r);
	}
}