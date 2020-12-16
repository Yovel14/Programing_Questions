int main()
{
	FastIO;

	int t,n;
	cin>>t;

	while(t--)
	{
		cin>>n;
		vector<int> v(n);
		for(int &it : v) cin>>it;

		int limit = n/2;
		for(int i = 0;i<limit;++i)
		{
			cout<<v[i]<<' '<<v[n-i-1]<<' ';
		}
		if(n%2==1) cout<<v[n/2];

		cout<<'\n';
	}

	return 0;
}