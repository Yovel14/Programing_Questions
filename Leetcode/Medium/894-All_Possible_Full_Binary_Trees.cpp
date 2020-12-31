#include <vector>
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode *> allPossibleFBT(int n)
{
	if (n % 2 == 0)
		return {};
	vector<TreeNode *> cache[n + 1];
	cache[1] = {new TreeNode()};

	for (int place = 3; place <= n; place += 2) // starting place from 3 because for even numbers there are no trees and thus I am also skipping by two
		for (int i = 0; i < place; i++)
			for (auto left : cache[i])
				for (auto right : cache[place - i - 1])
					cache[place].push_back(new TreeNode(0, left, right));
	return cache[n];
}