// This question is essentially how many uniuqe type of candies but amount will be less than n/2
// Time : O(n)
// Space : O(n)
int distributeCandies(vector<int> &c)
{
	unordered_set<int> u; // bitset of size 2*10^5+1 could be used for a faster O(1) but it's less space efficient
	int n = c.size();
	int limit = n >> 1;
	for (int i = 0; i < n && u.size() < limit; i++)
		u.insert(c[i]);

	return u.size();
}