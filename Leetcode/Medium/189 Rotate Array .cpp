// time : O(n)
// space : O(1)
void rotate(vector<int> &nums, int k)
{
	int n = nums.size();
	int remember = nums[0];
	int index;
	int temp;
	int i = 0;
	int count = 0;

	for (int start = 0; count < n; start++)
	{
		remember = nums[start];
		i = start;
		do
		{
			index = (i + k) % n;
			temp = nums[index];
			nums[index] = remember;
			remember = temp;
			count++;
			i = index;
		} while (i != start);
	}
}

// time : O(n)
// space : O(1)
void rotate(vector<int> &nums, int k)
{
	k %= nums.size();
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}