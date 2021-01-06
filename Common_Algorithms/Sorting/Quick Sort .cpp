#include <vector>
using namespace std;

void Choose_Pivot(vector<int> &v, int &l, int &r) // sets pivot as the the value on r index. the pivot will be the value which is the middle between l,r,(r+l)/2
{
	if (l != r)
	{
		int mid = l + ((r - l) >> 1); // mid index (the same as (r+l)/2 just this prevents integer overflow)
		if ((v[mid] <= v[l] && v[mid] >= v[r]) || (v[mid] >= v[l] && v[mid] <= v[r]))
			swap(v[mid], v[r]);
		if ((v[l] <= v[mid] && v[l] >= v[r]) || (v[l] >= v[mid] && v[l] <= v[r]))
			swap(v[l], v[r]);
		// v[r] is mid so leave it
	}
}
void QuickSort(vector<int> &v, int l, int r)
{
	if (l < r)
	{
		Choose_Pivot(v, l, r);
		int i = l;
		for (int j = l; j < r; j++)
			if (v[j] <= v[r])
				swap(v[j], v[i++]);
		swap(v[r], v[i]);
		QuickSort(v, l, i - 1);
		QuickSort(v, i + 1, r);
	}
}
vector<int> sortArray(vector<int> &nums)
{
	QuickSort(nums, 0, nums.size() - 1);
	return nums;
}