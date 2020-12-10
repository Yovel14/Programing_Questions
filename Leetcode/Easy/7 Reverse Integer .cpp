int reverse(int x) {
	if((x%10>2 && x>INT_MAX/10) || (x%10<-2 && x<INT_MIN/10)) return 0; // to shorten the time a bit 
	int out = 0;

	while(x)
	{
		int last_digit = x%10;
		if(out>INT_MAX/10  || out<INT_MIN/10 ) return 0;
		if((out==INT_MAX/10 && last_digit>7 ) && (out==INT_MIN/10 && last_digit>7 )) return 0;
		out = out*10 + last_digit;
		x/=10;
	}
	return out;
}