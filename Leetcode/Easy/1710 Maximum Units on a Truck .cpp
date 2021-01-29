// Time : O(nlog(n))
// Space : O(1)
static bool sortbysec(const vector<int> &a, const vector<int> &b)
{
	return (a[1] > b[1]);
}
int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
	sort(boxTypes.begin(), boxTypes.end(), sortbysec);
	int Usum = 0;
	int Bsum = 0;
	int i = 0;
	int n = boxTypes.size();
	int tBox;
	for (; i < n && Bsum < truckSize; i++)
	{
		tBox = min(truckSize - Bsum, boxTypes[i][0]);
		Bsum += tBox;
		Usum += tBox * boxTypes[i][1];
	}
	return Usum;
}