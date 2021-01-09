bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
{
	int wi1 = 0;
	int wi2 = 0;
	int ci1 = 0;
	int ci2 = 0;
	int n = word1.size();
	int m = word2.size();
	while (wi1 < n && wi2 < m)
	{
		if (ci1 >= word1[wi1].size())
		{
			wi1++;
			ci1 = 0;

			if (ci2 >= word2[wi2].size())
			{
				wi2++;
				ci2 = 0;
			}
		}
		else if (ci2 >= word2[wi2].size())
		{
			wi2++;
			ci2 = 0;
		}
		else if (word2[wi2][ci2++] != word1[wi1][ci1++])
			return false;
	}

	if (wi1 != n || wi2 != m)
		return false;
	return true;
}