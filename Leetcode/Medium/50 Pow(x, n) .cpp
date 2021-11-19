// Time : O(log2(n))
// Space : O(1)
double myPow2(double a, int n)
{
	if (n == 0)
		return 1;
	double res = myPow(a, n >> 1);
	if (n & 1)
		return res * res * a;

	return res * res;
}
double myPow(double a, int n)
{
	if (n < 0)
	{
		if (n == INT_MIN)
			return 1 / (a * myPow2(a, -(n + 1)));
		else
			return 1 / myPow2(a, -n);
	}
	return myPow2(a, n);
}

// Time : O(log2(n))
// Space : O(1)
double myPow2(double a, int n)
{
	if (n == 0)
		return 1;
	return myPow2(a * a, n / 2) * (n % 2 ? a : 1);
}
double myPow(double a, int n)
{
	return n >= 0 ? myPow2(a, n) : 1 / myPow2(a, n);
}

// Time : O(log2(n))
// Space : O(1)
double inline myPow2(double a, int n)
{
	if (a == 0)
		return 0;
	if (n == 0)
		return 1;

	double ans = 1;
	while (n)
	{
		if (n & 1)
			ans *= a;
		a *= a;
		n >>= 1;
	}
	return ans;
}

double myPow(double a, int n)
{
	if (n < 0)
	{
		if (n == INT_MIN)
			return 1 / (a * myPow2(a, -(n + 1)));
		else
			return 1 / myPow2(a, -n);
	}
	return myPow2(a, n);
}