#include<iostream>
using namespace std;

/**
	* Euclidean Algorithm: finding the greatest common divisor between two integers
	* Run time complexity: T(N) = O(log(N))
*/

long gcd( long m, long n )
{
	while( n != 0 )
	{
		long rem = m % n;
		m = n;
		n = rem;
	}
	return m;
}

int main() {
	
	cout << gcd(120, 220) << endl;
	
	return 0;
}