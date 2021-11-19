// this solutions is in addition to the solutions to the regular two sum problem

// Time: O(n)
// Space: O(1)
vector<int> twoSum(vector<int> &numbers, int target)
{
	int low = 0, high = numbers.size() - 1;

	while (low < high)
	{
		int diff = target - numbers[low];

		if (diff == numbers[high])
		{
			return {low + 1, high + 1};
		}
		else if (diff > numbers[high])
		{
			low++;
		}
		else
		{
			high--;
		}
	}

	return {-1, -1};
}

// Time: O(log(n!))
// Space: O(1)
int findIndex(vector<int> &arr, int low, int high, int target)
{
	while (low <= high)
	{
		int mid = low + ((high - low) >> 1);
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] > target)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return -1;
}

vector<int> twoSum(vector<int> &numbers, int target)
{
	for (int numIndex = 0; numIndex < numbers.size(); numIndex++)
	{
		int foundNumberIndex = this->findIndex(numbers, numIndex + 1, numbers.size() - 1, target - numbers[numIndex]);
		if (foundNumberIndex != -1)
		{
			return {numIndex + 1, foundNumberIndex + 1};
		}
	}

	return {-1, -1};
}