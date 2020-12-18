string longestPalindrome(string s)// O(n^2)
{
	// will try every middle position and go out from each center

	int mx_length = 0;
	int cur_length;
	int mx_begin = 0;
	int n = s.size();

	for(int mid = 0; mid<n; ++mid)// odd length palindromes
	{
		cur_length = 1;
		int left = mid-1;
		int right = mid+1;

		while(left>=0 && right<n && s[right] == s[left] )
		{
			cur_length+=2;
			--left;
			++right;
		}

		if(cur_length>mx_length)
		{
			mx_length = cur_length;
			mx_begin = left+1;
		}
	}

	for(int mid = 0; mid<n; ++mid)// even length palindromes
	{
		cur_length = 0;
		int left = mid;
		int right = mid+1;

		while(left>=0 && right<n && s[right] == s[left] )
		{
			cur_length+=2;
			--left;
			++right;
		}

		if(cur_length>mx_length)
		{
			mx_length = cur_length;
			mx_begin = left+1;
		}
	}

	return s.substr(mx_begin,mx_length);
}