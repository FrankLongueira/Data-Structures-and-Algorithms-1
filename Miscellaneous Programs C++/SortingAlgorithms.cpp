/* Simple insertion sort */
#include <iostream>
#include <vector>

using namespace std;


template <typename Comparable>
void insertionSort( vector<Comparable> &a, int left, int right ) {
	if(left < right){
		int size = right - left + 1;
		int j;
		for( int p = left + 1; p < right + 1; p++ ){
			Comparable tmp = a[ p ];
			for( j = p; (j > left)&&(tmp < a[ j - 1 ]); j-- ){
				a[ j ] = a[ j - 1];
			}
			a[ j ] = tmp;
		}
	}
}
	
template <typename Comparable>
void insertionSort( vector<Comparable> &a ) {
		insertionSort(a, 0, a.size()-1);
}
	

template <typename Comparable>
void shellSort( vector<Comparable> &a ) {
	for( int gap = a.size()/2; gap > 0; gap/= 2) {
		for( int i = gap; i < a.size(); i++){
			Comparable tmp = a[ i ];
			int j = i;
			
			for( ; (j >= gap) && (tmp < a[ j-gap ]); j-= gap ){
				a[ j ] = a[ j - gap ];
			}
			a[j] = tmp;
			
		}
	}
}


/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 **/

template <typename Comparable>
const Comparable & median3( vector<Comparable> & a, int left, int right ){
	int center = (left + right) / 2;
	if( a[center] < a[left] ){
		swap( a[left], a[center] );
	}
	if( a[right] < a[left] ){
		swap( a[left], a[right] );
	}
	if( a[right] < a[center] ){
		swap( a[center], a[right] );
	}
		
		// Place pivot at position right - 1
	swap( a[center], a[right - 1] );
	return a[right-1];
}


/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of comparable items.
 **/
 
 template <typename Comparable>
 void quicksort( vector<Comparable> & a, int left, int right ){
 	if ( left + 10 <= right ){
 		Comparable pivot = median3(a, left, right);
 			// Begin partitioning
 		int i = left;
 		int j = right - 1;
 		for( ; ; ){
 			while( a[++i] < pivot ) { };
 			while( pivot < a[--j] ) { };
 			if(i < j){
 				swap(a[i], a[j]);
 			}
 			else{
 				break;
 			}
 		}
 		
 		swap( a[i], a[right-1] ) ; // Restore pivot
 		
 		quicksort(a, left, i-1);
 		quicksort(a, i+1, right);
 	}
 	else{
 		insertionSort(a, left, right);
 	}
 }
 
 /* Quicksort algorithm driver */

template<typename Comparable>
void quicksort( vector<Comparable> & a ){
	quicksort(a, 0, a.size() - 1);
}

int main() {

	int a[] = {5, 3, 4, 9, 3, 4, 45, 33, 23, 12, 2, 75, 34, 45, 12, 90, 81, 17, 7, 54};
	unsigned a_size = sizeof(a)/sizeof(a[0]);
	
	vector<int> a_vec(a, a + a_size);

	//insertionSort(a_vec);
	//shellSort(a_vec);
	quicksort(a_vec);
		
	for( int i = 0; i < a_vec.size(); i++ ){
		cout << a_vec[i] << endl;
	}
	
	return 0;
}