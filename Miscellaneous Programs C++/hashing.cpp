#include <iostream>

using namespace std;

// Not an equitable distribution
int hash1( const string & key, int tableSize ){
	int hashVal = 0;
	for( int i = 0; i < key.length(); i++ ){
		hashVal += key[ i ];
	}
	return hashVal % tableSize;
}

// English is not random and hence a large portion of the table is not mapped to
int hash2( const string & key, int tableSize){
	return (key[0] + 27*key[1] + 729*key[ 2 ])% tableSize;
}


// Good hash function
int hash_good(const string & key, int tableSize){
	int hashVal = 0;
	
	for ( int i = 0; i < key.length( ); i++ ){
		hashVal = 37*hashVal + key[i];
	}
	hashVal %= tableSize;
	
	if( hashVal < 0 ) {
		hashVal += tableSize;
	}
	return hashVal;
}

int main() {
	
	cout << hash1("Frank", 10007) << endl;
	
	cout << endl;
	
	cout << hash2("Frank", 10007) << endl;
	
	cout << endl;
	
	cout << hash_good("Frank", 10007) << endl;
	return 0;
}