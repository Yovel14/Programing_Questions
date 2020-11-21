#include<vector>
//Definition for a binary tree node.
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        vector<TreeNode*> cache[n+1];
        cache[1] = {new TreeNode()};

        for(int place = 3; place<n+1;++place)
            for (int i = 1; i<place;++i)
                for(TreeNode* left: cache[i])
                    for(TreeNode* right: cache[place-1-i])
                        cache[place].push_back(new TreeNode(0,left,right));
        return cache[n];

    }
};