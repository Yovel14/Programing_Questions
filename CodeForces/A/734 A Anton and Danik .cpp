main()
{
	FastIO;

	// played n games
	string in;
	int ca = 0;
	int n;
	cin >> n;
	cin >> in;
	for (char &c : in)
	{
		if (c == 'A')
			ca++;
		else
			ca--;
	}
	if (ca == 0)
		cout << "Friendship";
	else if (ca > 0)
		cout << "Anton";
	else
		cout << "Danik";

	return 0;
}