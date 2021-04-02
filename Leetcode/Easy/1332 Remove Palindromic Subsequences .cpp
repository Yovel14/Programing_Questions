// Time : O(n) where n is the length of string s
// Space : O(1)
int removePalindromeSub(string s)
{
	// since I can remove a subsequence which doesnot have to be consecitive chars
	// if s isn't a palindrome I can just remove all of it
	// othewise I can remove either a and b in two operations
	int j = s.size() - 1;
	if (j == -1)
		return 0;
	for (int i = 0; i < j; i++, j--)
		if (s[i] != s[j])
			return 2;
	return 1;
}