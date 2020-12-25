string convert(string &s, int &numRows)
{
	if (numRows == 1 || numRows > s.size())
		return s;

	int n = s.size();
	string new_s = "";
	int adding = numRows + numRows - 2;

	for (int i = 0; i < numRows; i++)
	{
		for (int j = i; j < n; j += adding)
		{
			new_s += s[j];
			if (i != 0 && i != numRows - 1 && (j - i + adding - i) < n)
				new_s += s[j - i + adding - i];
		}
	}

	return new_s;
}