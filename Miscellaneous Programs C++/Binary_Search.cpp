#include <iostream>
#include <vector>

using namespace std;
/**
	* Performs the standard binary search using two comparisons per level
	* Returns index where item is found or -1 if not found.
	* Run-time Complexity: T(N) = O(log2(N))
*/

template <typename Comparable>
int binarySearch( const vector<Comparable> & a, const Comparable & x ){
	int low = 0;
	int high = a.size() - 1;
	const int NOT_FOUND = -1;
	
	while ( low <= high ){
		int mid = ( low + high ) / 2;
		
		if ( a[ mid ] < x )
			low = mid + 1;
		else if( a[ mid ] > x)
			high = mid - 1;
		else
			return mid; // Found
	}
	return NOT_FOUND;   // NOT_FOUND is defined as -1
	}
	
int main() {
	const int my_array[] = {1,2,6,8,14,19,25,29,35,48,59,76,94,105,210};
	int my_array_size = sizeof(my_array)/sizeof(int);
	vector<int> my_vector;
	
	my_vector.insert(my_vector.begin(), &my_array[0], &my_array[my_array_size]);

	// int find = 100;
	
	for( int find = 0; find < 211; find++){
	
		if(binarySearch(my_vector, find) == -1){
			cout << endl;
			cout << "The number " << find << " is not in the input vector!" << endl;
			cout << endl;
		}
		else{
			cout << endl;
			cout << "The number " << find << " can be found at " << flush;
			cout << "index " << binarySearch(my_vector, find) << " of the input vector." << endl;
			cout << endl;
		}
	}
	return 0;
}