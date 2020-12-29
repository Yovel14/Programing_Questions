int getSum(int a, int b) // a will hold th end result and b will hold the carry
{
	int carry;
	do
	{
		carry = a & b;
		a = a ^ b;
		b = (unsigned)carry << 1;
	} while (carry);
	return a;
}

int getSum(int a, int b)
{
	int result = 0;
	unsigned int carry = 0;
	for (int i = 0; i < 32; ++i)
	{
		result |= (a & (1 << i) ^ (b & (1 << i)) ^ carry);
		carry = ((a & (1 << i)) & (b & (1 << i))) | (((a & (1 << i)) ^ (b & (1 << i))) & carry);
		carry = (carry << 1);
	}
	return result;
}

int getSum(int a, int b) //recursive
{
	return b == 0 ? a : getSum(a ^ b, (unsigned)(a & b) << 1);
}