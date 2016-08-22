// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, SPRING 2016

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds one string
class Data {
public:
  string data;
  Data(const string &s) { data = s; }
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l) {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;

  ifstream input(filename.c_str());
  if (!input) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    string line;
    getline(input, line);
    l.push_back(new Data(line));
  }

  input.close();
}

// Output the data to a specified input file
void writeDataList(const list<Data *> &l) {
  string filename;
  cout << "Enter name of output file: ";
  cin >> filename;

  ofstream output(filename.c_str());
  if (!output) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << endl;

  // Write the data
  for (list<Data *>::const_iterator ipD = l.begin(); ipD != l.end(); ipD++) {
    output << (*ipD)->data << endl;
  }

  output.close();
}

void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  list<Data *> theList;
  loadDataList(theList);

  cout << "Data loaded.  Executing sort..." << endl;

  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds." << endl;

  writeDataList(theList);
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.

Data *holder[200000][10] = {};
Data *buckets[1200000] = {};
unsigned int counts[1200000] = {};



// An efficient comparison function for comparing two floating point values
// stored in strings (assuming they are long strings)
bool comp(const Data* data1, const Data* data2){
	int j = 20;
	int k = 20;
	while((data1->data)[j] != '.') { j-- ; }
	while((data2->data)[k] != '.') { k-- ; }
	
	if(j == k){
		return ((data1->data).compare(data2->data) < 0);
	}
	else{
		return (j < k);
	}
}

// Implementation of insertion sort using iterators
void insertionSort( list<Data *> &l, const list<Data *>::iterator &begin, const list<Data *>::iterator &end) {
	if(begin != end){
		list<Data *>::iterator j;
		for( list<Data *>::iterator p = next(begin, 1); p != end; p++ ){
			Data* tmp = *p;
			for( j = p; (j != begin)&&(comp(tmp, *(prev(j,1)))); j-- ){
				*j = *(prev(j,1));
			}
			*j  = tmp;
		}
	}
}	

// Insertion sort algorithm (driver)
void insertionSort( list<Data *> &l){
	insertionSort(l, l.begin(), l.end());
}	

// Implementation of MSD Radix sort using recursion. 
// l is the list of pointers to data objects
// begin & end are iterators for the section of a list to be sorted
// radix is which position is being sorted
// MAX is how many positions to sort recursively using MSD
// Assumes long strings of floating point numbers inside Data objects
void radixSort(list<Data *> &l, const list<Data *>::iterator begin, const list<Data *>::iterator end, int radix, int MAX){
	if((radix < MAX)&&(begin != end)){
		unsigned int counter[10] = {};
		for (list<Data *>::const_iterator itr = begin; itr != end; itr++) {
			int j = 20;
			while((((*itr)->data)[j]) != '.') { j-- ; }

			if((20 - j) > radix){
				holder[counter[0]][0] = *itr;
				(counter[0])++;
			}
			
			else{
				int slot = ((*itr)->data)[radix-(20-j)] - 48;
				holder[counter[slot]][slot] = *itr;
				(counter[slot])++;
			}
		}

		list<Data *>::iterator itr = begin;
		list<Data *>::iterator itr_bucket[10];

		for(int k = 0; k < 10; k++){
			itr_bucket[k] = itr;
			int start = 0;
			while(start != (counter[k])){
				*itr = holder[start][k];
				itr++;
				start++;
			}
			itr_bucket[k+1] = itr;
		}
		
		int tmp_radix = radix + 1;

		for(int i = 0; i < 10; i++){
			radixSort(l, itr_bucket[i], itr_bucket[i+1], tmp_radix, MAX);
		}
	}
}

// MSD Radix sort algorithm (driver)
void radixSort(list<Data *> &l, const int MAX){
		
radixSort(l, l.begin(), l.end(), 0, MAX);

}

// Implementation of counting sort
// Converts floating point numbers to integers by multiplying by 1000, buckets them,
// then iterates through the buckets to place them in the correct order.
void countingSort(list<Data *> &l){
	for (list<Data *>::const_iterator itr = l.begin(); itr != l.end(); itr++) {
		double tmp1 = round((1000*atof(((*itr)->data).c_str())));
		int tmp = (int)tmp1;
		buckets[tmp] = *itr;
		counts[tmp]++;
	}
	list<Data *>::iterator itr = l.begin();
	int k = 0;
	while(itr != l.end()){
		while(counts[k]){
			*itr = buckets[k];
			itr++;
			counts[k]--;
		}
		k++;
	}
}
		

void sortDataList(list<Data *> &l) {
  // Fill in this function
  if(((*l.begin())->data).substr(0,9) == ((*(++l.begin()))->data).substr(0,9)){
  	insertionSort(l);
  }
  else if(((*l.begin())->data).size() < 8){
  	countingSort(l);
  }
  else if(l.size() < 200000){
  	radixSort(l, 5);
  	insertionSort(l);
  }
  else{
  	radixSort(l, 6);
  	insertionSort(l);
  }  	
}