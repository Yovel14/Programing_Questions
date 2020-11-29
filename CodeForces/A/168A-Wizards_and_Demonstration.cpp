#include<iostream>
#include<vector>
#include<math.h>


using namespace std;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


	// n x y
	double n,x ,y;
	cin >> n >> x  >> y;

	cout<<max((int)ceil((y-x/n*100)/100*n),0);


	return 0;
}