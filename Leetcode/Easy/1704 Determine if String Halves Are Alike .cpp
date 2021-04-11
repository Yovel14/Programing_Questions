bool inline isVowel(char &c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

bool halvesAreAlike(string str)
{
	int countV = 0;
	int n = str.size();
	int limit = n / 2;
	for (int i = 0; i < limit; i++)
		if (isVowel(str[i]))
			countV++;
	for (int i = limit; i < n; i++)
		if (isVowel(str[i]))
			countV--;
	return countV == 0;
}