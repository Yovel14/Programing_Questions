bool isPalindrome(int x) {
	if(x<0 ||(x!=0 && x%10==0))return false;
	int out = 0;// I will add to y each of the digit from x while removing it until y>=x (this method will avoid overflow)
	// x will == y only if all char are the same 
	while(x>out)
	{
		out = 10*out + x%10;
		x/=10;
	}
	return (x==out || x== out/10);// x==out: for even number of digits // x == out/10: for odd number of digits
}