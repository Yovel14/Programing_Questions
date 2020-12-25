int divide(int &dividend, int &divisor) // note divisor != 0
{
	if ((dividend == -2147483648 && divisor == -1)) // overflow
		return 2147483647;
	if (dividend == 0)
		return 0;
	if (divisor == 1)
		return dividend;

	bool negitive = false;
	if ((divisor & (1 << 31)) != (dividend & (1 << 31))) // do they have the same sign (positive or negitive)
		negitive = true;

	if (divisor == -2147483648) // this if is based on the fact that INT_MAX =  2147483647 while INT_MIN = -2147483648
	{
		if (dividend != divisor)
			return 0;
		return 1;
	}

	int count = 0;

	if (divisor < 0)
		divisor = (~divisor) + 1;
	if (dividend < 0)
	{
		if (dividend == -2147483648)
		{
			dividend += divisor; // if I will not add divisor when I convert divedend to positive it will overflow
			count++;
		}
		dividend = (~dividend) + 1;
	}

	int adding = 1; // how much to add to count each round
	int reducer;	// how much to add to remove from dividend
	while (dividend >= divisor)
	{
		adding = 1;
		reducer = divisor;
		while (dividend >= reducer)
		{
			dividend -= reducer;
			count += adding;
			adding += adding;
			if (reducer < 1073741823)
				reducer += reducer;
		}
	}

	if (negitive)
		return ~count + 1;
	return count;
}