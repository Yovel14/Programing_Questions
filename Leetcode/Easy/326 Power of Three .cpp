// Time : O(log3(n))
// Space : O(1)
bool isPowerOfThree(int n)
{
	if (n < 1)
		return false;
	if (n == 1162261467)
		return true;
	if (n > 1162261467)
		return false;

	int a = 1;
	while (a < n)
		a *= 3;
	return a == n;
}

// Time : O(1)
// Space : O(1)
bool isPowerOfThree(int n)
{
	if (n < 1)
		return false;
	double reminder;
	return modf(log10(n) / log10(3), &reminder) == 0.0;
}

// Time : O(1)
// Space : O(1)
bool isPowerOfThree(int n)
{
	if (n < 1)
		return false;
	return 1162261467 % n == 0; // highst power of 3 which fits in an integer should devid by all powers of 3 below or equal to it;
}

// Time : O(log3(n))
// Space : O(1)
string converTobase3(int n)
{
	string ans = "";
	while (n)
	{
		ans.push_back(n % 3);
		n /= 3;
	}
	return ans;
}
bool isPowerOfThree(int n)
{
	if (n < 1)
		return false;
	string s = converTobase3(n);
	int count = 0;
	for (int i = 0; i < s.size() && count < 2; i++)
		if (s[i] != 0)
			count += int(s[i]);
	return count == 1;
}