class Codec
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode *root)
	{
		if (root == nullptr)
			return "n";

		return std::to_string(root->val) + ' ' + this->serialize(root->left) + ' ' + this->serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data)
	{
		int t = 0;
		return deserializeRec(data, t);
	}

	TreeNode *deserializeRec(string &data, int &spaceIndex)
	{
		int nextSpaceIndex = data.find(' ', spaceIndex);
		string val = data.substr(spaceIndex, nextSpaceIndex - spaceIndex);

		if (val == "n")
		{
			spaceIndex = nextSpaceIndex + 1;
			return nullptr;
		}

		TreeNode *cur = new TreeNode(stoi(val));
		spaceIndex = nextSpaceIndex + 1;
		cur->left = deserializeRec(data, spaceIndex);
		cur->right = deserializeRec(data, spaceIndex);

		return cur;
	}
};