int firstBadVersion(int n)
{
	// jut a simple binary search
	int low = 1;
	int high = n;
	int mid;
	while (low < high)
	{
		mid = low + ((high - low) >> 1);
		if (isBadVersion(mid))
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}