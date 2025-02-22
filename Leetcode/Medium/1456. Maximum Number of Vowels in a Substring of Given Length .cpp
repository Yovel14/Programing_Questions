// Time: O(n) Sliding windows solution
class Solution
{
private:
	bool isVowel(char c)
	{
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}

public:
	int maxVowels(string s, int k)
	{
		int count = 0;
		int mx = 0;
		int i = 0;

		for (i = 0; i < s.size() && i < k; i++)
			if (isVowel(s[i]))
				count++;

		mx = count;

		for (; i < s.size(); i++)
		{
			if (isVowel(s[i]))
				count++;

			if (isVowel(s[i - k]))
				count--;

			if (count > mx)
				mx = count;
		}

		return mx;
	}
};