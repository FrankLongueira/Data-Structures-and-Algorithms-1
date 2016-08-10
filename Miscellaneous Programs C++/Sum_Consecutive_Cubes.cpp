#include <iostream>

using namespace std;

int sum( int n )
{
	int partialSum = 0;
	
	for ( int i = 1; i<=n; i++ )
		partialSum += i * i * i;
	return partialSum;
}
int main() {
	
	for( int i = 1; i <= 15; i++ ) {
		cout << sum(i) << endl;
	}
	
	return 0;

}