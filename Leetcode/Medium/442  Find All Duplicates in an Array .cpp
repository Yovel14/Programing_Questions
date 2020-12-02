#include <vector>
#include <cstdlib>

using namespace std;

class Solution
{
public:
	vector<int> findDuplicates(vector<int> &nums)
	{
		vector<int> out = {};
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			if (nums[abs(nums[i]) - 1] < 0)
				out.push_back(abs(nums[i]));
			else
				nums[abs(nums[i]) - 1] *= -1;
		}
		return out;
	}
};