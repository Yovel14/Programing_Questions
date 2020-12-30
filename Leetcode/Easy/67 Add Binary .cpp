string addBinary(string a, string b)
{
	int ai = a.size() - 1;
	int bi = b.size() - 1;
	string res = "";
	bool carry = false;

	for (; ai >= 0 && bi >= 0; ai--, bi--)
	{
		if ((a[ai] == '1' && b[bi] == '1' && !carry) || (((a[ai] == '1') != (b[bi] == '1') && carry))) // two are 1
		{
			res = '0' + res;
			carry = true;
		}
		else if (a[ai] == '1' && b[bi] == '1' && carry) // three are 1
		{
			carry = true;
			res = '1' + res;
		}
		else if (!carry && a[ai] == '0' && b[bi] == '0')
			res = '0' + res;
		else
		{
			carry = false;
			res = '1' + res;
		}
	}

	for (; ai >= 0; ai--)
	{
		if (!carry)
			res = a[ai] + res;
		else
		{
			if (a[ai] == '0')
			{
				carry = false;
				res = '1' + res;
			}
			else
				res = '0' + res;
		}
	}

	for (; bi >= 0; bi--)
	{
		if (!carry)
			res = b[bi] + res;
		else
		{
			if (b[bi] == '0')
			{
				carry = false;
				res = '1' + res;
			}
			else
				res = '0' + res;
		}
	}

	if (carry)
		return '1' + res;
	return res;
}