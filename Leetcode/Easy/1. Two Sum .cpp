#include <vector>
#include <unordered_map>
using namespace std;

class Solution // O(n^2)
{

public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		int left_over, len = nums.size();

		for (int i = 0; i < len; ++i)
		{
			left_over = target - nums[i];
			for (int j = i + 1; j < len; ++j)
				if (nums[j] == left_over)
					return {i, j};
		}
		return {};
	}
};

class Solution // O(n)
{

public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		int len = nums.size();
		std::unordered_map<int, int>::const_iterator left_over;
		unordered_map<int, int> exist;

		for (int i = 0; i < len; ++i)
		{
			left_over = exist.find(target - nums[i]);
			if (left_over != exist.end())
				return {i, left_over->second};
			exist.insert({nums[i], i});
		}
		return {};
	}
};