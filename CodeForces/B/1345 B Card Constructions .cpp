#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
#include<algorithm>
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
/*
let a be: 
h = 1	:	2 laying cards = 2*1
h = 2	:	4 laying cards = 2*2
h = 3	:	6 laying cards = 2*3
.
.
.

let b be:
h = 1	:	0 laying cards
h = 2	:	1 laying cards
h = 3	:	2 laying cards 
.
.
.

sum of a:
= 2*(1+2+3+4...)
= 2*(h*(h+1)/2)
= h^2 + h

sum of b:
= 0+1+2+3...
= h*(h-1 + 0)/2
= (h^2-h)/2
= (h^2)/2 - h/2

the sum of a + the sum of b:
h^2 + h + (h^2)/2 + h/2
= 1.5*h*h+0.5*h

quadratic formula for the sum of a and b:
n = 1.5*h*h+0.5*h2
0 = 1.5*h*h+0.5*h - n
h = floor(-0.5/3+sqrt(0.5+6*n)/3)

I only use + because h has to be positive
*/
/*
int amount(double n) // using math
{
	double h;
	int count = 0;
	while(n>1){
	h = floor(-0.5/3+sqrt(0.5+6*n)/3);
	n-=1.5*h*h+0.5*h;
	++count;
	}
	return count;
}
*/

int amount(double n)// I will creat the biggest I can each time add to counter
{
	int count = 0;
	while( n>1 )
	{
		// for level i the amount of cards is 3*i-1
		for(int i = 1;n>=3*i-1;++i) 
			n-=3*i-1;
		++count;
	}
	return count;

}

int main()
{
	FastIO;
	int t;
	cin>>t;
	while(t--)
	{
		double n;
		cin>>n;
		cout<<amount(n)<<'\n';
	}
	return 0;
}