#include<vector>
using namespace std;

void Merge(vector<int> &v,int l,int m,int r)
{
	int l1 = m-l+1;
	int l2 = r-m;

	int temp1[l1];
	for(int i = 0;i<l1;++i)// fill temp1
		temp1[i] = v[i+l];

	int temp2[l2];
	for(int i = 0;i<l2;++i)// fill temp2
		temp2[i] = v[i+m+1];

	int i = 0, j = 0, k = l;
	while(i<l1 && j<l2)// join temp1 and temp2 to v
	{
		if(temp1[i]<=temp2[j])
			v[k++] = temp1[i++];
		else
			v[k++] = temp2[j++];
	}

	while (i<l1)// if there is any value from temp1 to add fill it into v
		v[k++] = temp1[i++];

	while (j<l2)// if there is any value from temp2 to add fill it into v
		v[k++] = temp2[j++];
}

void Merge_Sort(vector<int> &v,int l = 0,int r = -1)
{
	if(r == -1) r = v.size()-1;

	if(l<r)
	{
		int mid = l+(r-l)/2;// mid without the overflow risk

		Merge_Sort(v,l,mid);
		Merge_Sort(v,mid+1,r);
		Merge(v,l,mid,r);
	}
}