int totalMoney(int n) // there is probobly a formula to use completely
{
	int mondey = 1;
	int ans = 0;

	while (n > 0)
	{
		ans += min(n, 7) * (mondey + mondey + min(n, 7) - 1) / 2;
		mondey++;
		n -= 7;
	}
	return ans;
}