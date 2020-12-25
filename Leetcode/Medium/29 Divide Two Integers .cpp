int divide(int dividend, int divisor) // note divisor != 0
{
	if ((dividend == -2147483648 && divisor == -1)) //overflow
		return 2147483647;

	if (dividend == 0)
		return 0;
	if (divisor == 1)
		return dividend;

	bool negitive = false;
	if ((divisor & (1 << 31)) != (dividend & (1 << 31))) // do they have the same sign (positive or negitive)
		negitive = true;

	// converting divisor and dividend to negitive is to avoid overflow if one of them is equal to INT_MIN
	if (divisor > 0)
		divisor = ~divisor + 1;
	if (dividend > 0)
		dividend = ~dividend + 1;

	int count = 0;
	int adding;	 // how much to add to count each time
	int reducer; // how much to remove from dividend
	while (dividend <= divisor)
	{
		adding = 1;
		reducer = divisor;
		while (dividend <= reducer)
		{
			dividend -= reducer;
			count += adding;
			adding += adding;
			if (reducer >= -1073741824) // to avoid overflow
				reducer += reducer;
		}
	}

	if (negitive)
		return ~count + 1;
	return count;
}