// time : O(nlog(n))
// space : O(1)
int numRescueBoats(vector<int> &people, int limit)
{
	int count = 0;

	sort(people.begin(), people.end());

	int l = 0;
	int r = people.size() - 1;
	while (l < r)
	{
		if (people[l] + people[r] > limit)
			r--;
		else
		{
			r--;
			l++;
		}

		count++;
	}
	return count + (r == l);
}