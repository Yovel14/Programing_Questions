void getcomb(string &digits, int index, vector<string> &com, string build_string) // works in O(3^n * 4^n) where n is number of digits that map to 4 letters number and m  number map to 4 letters
{
	if (index == digits.size())
	{
		if (build_string != "")
			com.push_back(build_string); // this is time consuming thus I can calculate the exact amount and of possible combinations and add them by index to the last empty spot
		return;
	}

	if (digits[index] == '2')
	{
		index++;
		getcomb(digits, index, com, build_string + 'a');
		getcomb(digits, index, com, build_string + 'b');
		getcomb(digits, index, com, build_string + 'c');
		return;
	}
	else if (digits[index] == '3')
	{
		index++;

		string before = build_string;
		getcomb(digits, index, com, build_string + 'd');
		getcomb(digits, index, com, build_string + 'e');
		getcomb(digits, index, com, build_string + 'f');
		return;
	}
	else if (digits[index] == '4')
	{
		index++;

		getcomb(digits, index, com, build_string + 'g');
		getcomb(digits, index, com, build_string + 'h');
		getcomb(digits, index, com, build_string + 'i');
		return;
	}
	else if (digits[index] == '5')
	{
		index++;

		getcomb(digits, index, com, build_string + 'j');
		getcomb(digits, index, com, build_string + 'k');
		getcomb(digits, index, com, build_string + 'l');
		return;
	}
	else if (digits[index] == '6')
	{
		index++;

		getcomb(digits, index, com, build_string + 'm');
		getcomb(digits, index, com, build_string + 'n');
		getcomb(digits, index, com, build_string + 'o');
		return;
	}
	else if (digits[index] == '7')
	{
		index++;

		getcomb(digits, index, com, build_string + 'p');
		getcomb(digits, index, com, build_string + 'q');
		getcomb(digits, index, com, build_string + 'r');
		getcomb(digits, index, com, build_string + 's');
		return;
	}
	else if (digits[index] == '8')
	{
		index++;

		getcomb(digits, index, com, build_string + 't');
		getcomb(digits, index, com, build_string + 'u');
		getcomb(digits, index, com, build_string + 'v');
		return;
	}
	else if (digits[index] == '9')
	{
		index++;

		getcomb(digits, index, com, build_string + 'w');
		getcomb(digits, index, com, build_string + 'x');
		getcomb(digits, index, com, build_string + 'y');
		getcomb(digits, index, com, build_string + 'z');
		return;
	}
}
vector<string> letterCombinations(string &digits)
{
	if (digits == "")
		return {};
	vector<string> com;
	getcomb(digits, 0, com, "");
	return com;
}

// Thinking a bit more this could be done just with loops
// create a vector of the expected size of the bombinations
// run over it and each time add new char and copyt the array to itself and do it again until done