// brute force
// TLE
// Time: O(n^2) where n is the length of nums
// Space: O(m) where m is the number of missing numbers
vector<int> findDisappearedNumbers(vector<int> &nums)
{
	vector<int> missingNumbers = vector<int>();

	for (int numberToCheck = 1; numberToCheck <= nums.size(); numberToCheck++)
	{
		bool found = false;

		for (int num : nums)
		{
			if (numberToCheck == num)
			{
				found = true;
				break;
			}
		}

		if (!found)
		{
			missingNumbers.push_back(numberToCheck);
		}
	}

	return missingNumbers;
}

// hash set
// Time: O(n)
// Space: O(n)
vector<int> findDisappearedNumbers(vector<int> &nums)
{
	set<int> numSet = set<int>(nums.begin(), nums.end());
	vector<int> missingNumbers = vector<int>();

	for (int numberToCheck = 1; numberToCheck <= nums.size(); numberToCheck++)
	{
		if (numSet.find(numberToCheck) == numSet.end())
		{
			missingNumbers.push_back(numberToCheck);
		}
	}

	return missingNumbers;
}

// sort and binary search
// Time O(n*log(n) + n*log(n)) = o(n*log(n))
// Space : O(m)
vector<int> findDisappearedNumbers(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	vector<int> missingNumbers = vector<int>();

	for (int neededNumber = 1; neededNumber <= nums.size(); neededNumber++)
	{
		std::vector<int>::iterator foundNumber = std::lower_bound(nums.begin(), nums.end(), neededNumber);

		if (foundNumber == nums.end() || *foundNumber != neededNumber)
		{
			missingNumbers.push_back(neededNumber);
		}
	}

	return missingNumbers;
}

// sort and two pointer solution
// Time: O(n*log(n)) but still faster then the above solution because because it only sorts and doesn't binary search n times
// Space: O(m)
vector<int> findDisappearedNumbers(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	vector<int> missingNumbers = vector<int>();
	int numberToCheck = 1;

	for (int numsindex = 0; numsindex < nums.size();)
	{
		if (numberToCheck != nums[numsindex])
		{
			if (numberToCheck < nums[numsindex])
			{
				missingNumbers.push_back(numberToCheck);
				numberToCheck++;
			}
			else
			{
				numsindex++;
			}
		}
		else
		{
			numberToCheck++;
			numsindex++;
		}
	}

	for (; numberToCheck <= nums.size(); numberToCheck++)
	{
		missingNumbers.push_back(numberToCheck);
	}

	return missingNumbers;
}

// boolean array
// Time: O(n)
// Space: O(n)
vector<int> findDisappearedNumbers(vector<int> &nums)
{
	bool *found = new bool[nums.size() + 1]();

	for (int num : nums)
	{
		found[num] = true;
	}

	vector<int> missingNumbers = vector<int>();
	for (int foundNumber = 1; foundNumber <= nums.size(); foundNumber++)
	{
		if (!found[foundNumber])
		{
			missingNumbers.push_back(foundNumber);
		}
	}

	return missingNumbers;
}

// space optimized boolean array
// Time: O(n)
// Space: O(1)
vector<int> findDisappearedNumbers(vector<int> &nums)
{
	for (int num : nums)
	{
		int index = std::abs(num) - 1;
		nums[index] = -std::abs(nums[index]);
	}

	vector<int> missingNumbers = vector<int>();

	for (int numIndex = 0; numIndex < nums.size(); numIndex++)
	{
		if (nums[numIndex] < 0)
		{
			nums[numIndex] = -nums[numIndex];
		}
		else
		{
			missingNumbers.push_back(numIndex + 1);
		}
	}

	return missingNumbers;
}

// place value at the correct index
// Time: O(n)
// Space: O(1)
vector<int> findDisappearedNumbers(vector<int> &nums)
{
	for (int &num : nums)
	{
		while (num != nums[num - 1])
		{
			swap(num, nums[num - 1]);
		}
	}

	vector<int> missingNumbers = vector<int>();
	for (int numsIndex = 0; numsIndex < nums.size(); numsIndex++)
	{
		if (nums[numsIndex] - 1 != numsIndex)
		{
			missingNumbers.push_back(numsIndex + 1);
		}
	}

	return missingNumbers;
}