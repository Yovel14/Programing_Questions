// Time : O(n)
// Space : O(1)
int fib(int n)
{
	int a = 0;
	int b = 1;
	while (n--)
	{
		int tmp = b;
		b += a;
		a = tmp;
	}

	return a;
}

// Time : O(1)
// Space : O(1)
int fib(int n)
{
	double goldenRatio = (1 + sqrt(5)) / 2;
	return (int)round(pow(goldenRatio, n) / sqrt(5));
}

// this could also be solved with matrix exponentiation and  memoization;