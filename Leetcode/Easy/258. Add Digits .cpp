class Solution
{
public:
	int addDigits(int num)
	{
		while (num / 10 != 0)
		{
			int sum = 0;
			while (num)
			{
				sum += num % 10;
				num /= 10;
			}

			num = sum;
		}

		return num;
	}
};