string longestPalindrome(string s)
{
	// from each possible center open to check for a palindrome

	int n = s.size();
	int l, r;
	int mx = 0;					// max palindromic subsequence
	int si = -1;				// start index
	for (int c = 0; c < n; c++) // c : center
	{
		// odd length;
		l = c - 1;
		r = c + 1;
		while (l >= 0 && r < n && s[l] == s[r])
		{
			l--;
			r++;
		}
		if (r - l - 1 > mx)
		{
			mx = r - l - 1;
			si = l + 1;
		}

		// even length;
		l = c;
		r = c + 1;
		while (l >= 0 && r < n && s[l] == s[r])
		{
			l--;
			r++;
		}
		if (r - l - 1 > mx)
		{
			mx = r - l - 1;
			si = l + 1;
		}
	}
	return s.substr(si, mx);
}