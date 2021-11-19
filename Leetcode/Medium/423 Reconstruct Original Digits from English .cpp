// Time : O(n) where n is the length of s
// Time : O(26 + 10) == O(1) // excluding the answer length
string originalDigits(string &s)
{
	int Freq[26] = {};

	for (char &c : s)
		Freq[c - 'a']++;
	//{"zero/","one","two/","three","four/","five","six/","seven","eight/","nine"}
	int nums[10] = {};
	nums[0] = Freq['z' - 'a'];
	nums[2] = Freq['w' - 'a'];
	nums[4] = Freq['u' - 'a'];
	nums[6] = Freq['x' - 'a'];
	nums[8] = Freq['g' - 'a'];
	nums[1] = Freq['o' - 'a'] - nums[0] - nums[2] - nums[4];
	nums[5] = Freq['f' - 'a'] - nums[4];
	nums[3] = Freq['h' - 'a'] - nums[8];
	nums[7] = Freq['s' - 'a'] - nums[6];
	nums[9] = (Freq['n' - 'a'] - nums[1] - nums[7]) >> 1; // because n apears twice in nine we divide by 2

	// building ans could be done faster with binary exponentiation
	string ans = "";
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < nums[i]; j++)
			ans.push_back('0' + i);

	return ans;
}

// Time : O(n) + O(1) + O(n)*O(1) = O(n) where n is the length of s
// Time : O(26 + 10) == O(1) // excluding the answer length
string originalDigits(string &s)
{
	int sFreq[26] = {};

	for (char &c : s)
		sFreq[c - 'a']++;

	vector<unordered_map<int, int>> numsFreq(10);
	string numsS[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	for (int i = 0; i < 10; i++)
		for (char &c : numsS[i])
			numsFreq[i][c - 'a']++;

	int countNums[10] = {};
	int nums[] = {0, 2, 4, 6, 8, 1, 5, 9, 7, 3}; // 0,2,4,6,8 contain unique digits all the numers after contain unique digits compare to the ones before it
	for (int i = 0; i < 10;)
	{
		bool possible = true;
		for (auto it : numsFreq[nums[i]])
			if (sFreq[it.first] < it.second)
			{
				possible = false;
				break;
			}

		if (possible)
		{
			for (auto it : numsFreq[nums[i]])
				sFreq[it.first] -= it.second;
			countNums[nums[i]]++;
		}
		else
			i++;
	}
	string ans = "";
	for (int i = 0; i < 10; i++)
		while (countNums[i]--)
			ans.push_back('0' + i);
	return ans;
}