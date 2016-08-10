#include<iostream>

using namespace std;

/**
	Raising an integer to a power (which is also an integer)
	Run-time Complexity: T(N) = O(log2(N))
*/

long pow( long x, int n )
{
	if( n == 0)
		return 1;
	if( n == 1 )
		return x;
	if( (n % 2) == 0 )
		return pow( x * x, n/2 );
	else
		return pow( x * x, n/2) * x;
}

int main() {
	
	
	cout << pow(3,4) << endl;
	
	return 0;

}