#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <string>
#include "SimpleList.h"

using namespace std;

/*
The following is the derived class "Queue" that was taken from the abstract base class "Simplelist." This provides the functionality of a queue data structure.
The pure virtual functions of "Simplelist" were implemented in "Queue" by calling appropriate protected member functions in "Simplelist."
*/

template <class DataType> 
class Queue : public SimpleList<DataType> {
	public:
		Queue(const string &n) : SimpleList<DataType>(n) {}
		void push(const DataType &val) { SimpleList<DataType>::insertEnd(val); }
		DataType pop()  { return SimpleList<DataType>::removeStart(); }
};



#endif /* QUEUE_H_ */