int main()
{
	FastIO;

	// n friends met
	// the i-th person ocupies rectangle of width w[i] and h[i]
	// the image takes (sum of all widths )*( the max of heights )
	// idea take the sum of all width
	// find the two heighest people
	// and use to get the minimal size

	int n,h1 = 0,h2 = 0,width_sum = 0;
	cin>>n;
	vector<pair<int,int>> f(n);
	for(pair<int,int> &it: f) 
	{
		// first = width
		cin>>it.first;
		width_sum+=it.first;

		// second = height
		cin>>it.second;
		if(it.second>h1)
		{
			h2 = h1;
			h1 = it.second;
		}
		else if(it.second > h2) h2 = it.second;
	}

	for(pair<int,int> &it: f)
	{
		cout<<(it.second == h1 ? h2:h1)*(width_sum-it.first)<<' ';
	}

	return 0;
}