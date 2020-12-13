int coinChange(vector<int>& coins, int amount) { // dp method
	if(amount == 0) return 0;
	int a[++amount];
	a[0] = 0;
	
	sort(coins.begin(),coins.end());// sorting to be able to skip the coins once they are bigger than i thus shortning the time
	
	for(int i = 1;i<amount;++i)
	{
		a[i] = -1;
		for(int &coin: coins)
		{
			if(i<coin) break;
			
			if(a[i-coin] != -1){// I am testing for min value and -1 will always be 
				
				if(a[i] == -1) a[i] = a[i-coin] + 1;// if a[i] is -1 it will always be the min value
				
				else if(a[i-coin]+1<a[i]) // checking for min value
					a[i] = a[i-coin]+1;
			}
		
		}
	}
	return a[amount-1];
}


// recursive

void try_all(vector<int>& coins,int amount, int index, int cur_coin_count, int &min_coins)
{
	if(index<0) return;
	if(amount%coins[index]==0)
	{
		min_coins = min(min_coins,cur_coin_count+amount/coins[index]);
		return;
	}

	for(int i = amount/coins[index]; i>=0 ;--i)
	{
		if(i+cur_coin_count+1>=min_coins) return;

		try_all(coins,amount-i*coins[index],index-1,cur_coin_count+i,min_coins);
	}
}

int coinChange(vector<int>& coins, int amount)
{
	if(amount == 0) return 0;
	if(coins.size() == 0) return -1;
	sort(coins.begin(),coins.end());
	int min_coins = INT_MAX;
	try_all(coins,amount,coins.size()-1,0,min_coins);
	return min_coins==INT_MAX ? -1: min_coins;
}