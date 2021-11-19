// Time : O(26*A.size() + 26*B.size()) = O(A.size() + B.size())
// Space : O(A.size()+ B.size())
vector<int> inline count(string &s)
{
	vector<int> freq(26, 0);
	for (char &c : s)
		freq[c - 'a']++;
	return freq;
}
vector<string> wordSubsets(vector<string> &A, vector<string> &B)
{
	vector<string> ans;
	vector<int> bFreq(26, 0);
	for (int i = 0; i < B.size(); i++)
	{
		vector<int> tmp = count(B[i]);
		for (int j = 0; j < 26; j++)
			bFreq[j] = max(bFreq[j], tmp[j]);
	}

	vector<int> aFreq;
	for (string &a : A)
	{
		bool sub = true;
		aFreq = count(a);

		for (int i = 0; i < 26; i++)
		{
			if (aFreq[i] < bFreq[i])
			{
				sub = false;
				break;
			}
		}

		if (sub)
			ans.push_back(a);
	}
	return ans;
}