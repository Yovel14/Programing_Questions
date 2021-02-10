// Trie Data structure
// Time : O(n * 32  + n*32) = O(n)  where n is the length of nums
// Space : O(n)
class Trie
{
public:
	Trie *child[2] = {nullptr};
};
class Solution
{
public:
	void InsertNumber(int n, Trie *head)
	{
		int ci;
		for (int i = 31; i != -1; i--)
		{
			ci = (n >> i) & 1;

			if (!head->child[ci])
				head->child[ci] = new Trie();

			head = head->child[ci];
		}
	}
	int findMaximumXOR(vector<int> &nums)
	{
		int n = nums.size();
		int ans = 0;
		int pa; // possible ans
		int ci; // child index
		Trie *root = new Trie();

		for (int i = 0; i < n; i++)
			InsertNumber(nums[i], root);

		Trie *head;
		// find mx xor for each in nums
		for (int i = 0; i < n; i++)
		{
			// find mx xor for nums[i]
			pa = 0;
			head = root;

			for (int offset = 31; offset != -1; offset--)
			{
				ci = (nums[i] >> offset) & 1;
				if (head->child[(ci ^ 1)])
				{
					head = head->child[(ci ^ 1)];
					pa |= (1 << offset);
				}
				else
					head = head->child[ci];
			}
			ans = max(ans, pa);
		}

		return ans;
	}
};

// TLE
// Time : O(n^2)
// Space : O(1)
int findMaximumXOR(vector<int> &nums)
{
	int mx = 0;
	int n = nums.size();
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			mx = max(mx, nums[i] ^ nums[j]);
	return mx;
}