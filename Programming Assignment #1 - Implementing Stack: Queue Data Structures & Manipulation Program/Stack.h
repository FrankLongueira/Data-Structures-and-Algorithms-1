#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <string>
#include "SimpleList.h"

using namespace std;

/*
The following is the derived class "Stack" that was taken from the abstract base class "Simplelist." This provides the functionality of a stack data structure.
The pure virtual functions of "Simplelist" were implemented in "Stack" by calling appropriate protected member functions in "Simplelist."
*/

template <class DataType> 
class Stack : public SimpleList<DataType> {
	public:
		Stack(const string &n): SimpleList<DataType>(n) {}
		void push(const DataType &val) { SimpleList<DataType>::insertStart(val); }
		DataType pop() { return SimpleList<DataType>::removeStart(); }
};

#endif /* STACK_H_ */