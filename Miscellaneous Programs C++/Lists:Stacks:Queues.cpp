// Messing with Lists/Vectors


#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename Container>

void removeEveryOtherItem( Container & lst ) {
	typename Container::iterator itr = lst.begin();
	while( itr != lst.end() ) {
		itr = lst.erase( itr );
		if( itr != lst.end() ) {
			itr++;
		}
	}
}


int main() {
	/*
	list<int> integers(2,100);
	
	integers.push_back(5);
	integers.push_front(1);
	// list<int> integer_list_copied(integers);
	integers.pop_back();
	// cout << integers.size() << endl;
	// cout << "Is the container empty? " << integers.empty() << endl;
	cout << "The first number in this list is: " << integers.front() << endl;
	cout << "The last number in this list is: " << integers.back() << endl;

	// integers.clear();
	// cout << "Is the container empty? " << integers.empty() << endl;
	// cout << integers.size() << endl;
	
	
	vector<int> my_vector(2,19);
	my_vector[my_vector.size() - 1] = 234;
	cout << "The first number in this vector is : " << my_vector.at(0) << endl;
	cout << "The last number in this vector is : " << my_vector.back() << endl;
	cout << "The capacity of this vector is : " << my_vector.capacity() << endl;
	*/
	
	vector<int> v(10,0);
	
	for( vector<int>::iterator itr = v.begin(); itr != v.end(); itr++ ) {
		cout << *itr << endl;
	}
	removeEveryOtherItem(v);
	
	cout << endl;
	cout << endl;
	
	for( vector<int>::iterator itr = v.begin(); itr != v.end(); itr++ ) {
		cout << *itr << endl;
	}
	return 0;
}
