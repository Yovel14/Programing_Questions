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
			adding += adding;			// shift 1 left could be used instead because adding number to itself it to multiply by 2
			if (reducer >= -1073741824) // to avoid overflow
				reducer += reducer;		// if reducer was positive shift 1 left could be used instead because adding number to itself it to multiply by 2 (because the way negitive numbers are represented negitive numbers can't be shifted to be multiplied)
		}
	}

	if (negitive)
		return ~count + 1;
	return count;
}

// bit manipulation
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

	int count = 0;

	if (divisor < 0)
	{
		if (divisor == -2147483648)
		{
			if (dividend != -2147483648)
				return 0;
			else
				return 1;
		}
		divisor = ~divisor + 1;
	}

	if (dividend < 0)
	{
		if (dividend == -2147483648)
		{
			dividend += divisor;
			count++;
		}
		dividend = ~dividend + 1;
	}

	for (int shift = 31; shift >= 0; shift--) // essentially find the biggest multiple of divisor which is bigger than dividend and add exponent to count
	{
		if ((dividend >> shift) >= divisor)
		{
			count += (1 << shift); // (1<<shift) if the multiple of divisor which is bigger than dividend

			dividend -= (divisor << (shift)); // remove the multiple from dividend
		}
	}

	if (negitive)
		return ~count + 1;
	return count;
}