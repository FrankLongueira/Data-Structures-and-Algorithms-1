#ifndef SIMPLELIST_H_
#define SIMPLELIST_H_

#include <iostream>
#include <string>


using namespace std;

/*
The following code implements an abstract base class called "Simplelist" that provides some simple
aspects of singly linked list functionality. 

Inside the class is a private nested class called "Node" that stores data & a pointer to the next 
node in the list.

The head & tail data members are "dummy nodes" that contain pointers to the beginning & end of the
list, respectively. If tail is pointing to NULL, this implies the Simplelist is empty.
*/

template <class DataType> 
class SimpleList {
	public:
		SimpleList(const string &name) {this->name = name;  init(); }
		virtual void push(const DataType &val) = 0;
		virtual DataType pop() = 0;
		
	private:
		string name;
		class Node {
              public:
              	Node(const DataType &d = DataType(), Node* n = NULL) : data( d ), next( n ) { }
                DataType data;
                Node* next;
        };
		
		void init() {
			head = new Node;
			tail = new Node;
			head->next = tail;
			tail->next = NULL;
		}
		Node* head;
		Node* tail;
		
	public:
		string getName() {return name;}
		Node* getStart() {return head->next;}
		Node* getEnd() {return tail->next;}
		
	protected:
		void insertStart(const DataType &val) { 
			Node* pVal = new Node(val, head->next);
			head->next = pVal;
			if(tail->next == NULL){ 
				tail->next = pVal;
				pVal->next = NULL;
			}
		}
			
		void insertEnd(const DataType &val) {
			Node* pVal = new Node(val, NULL);

			if(tail->next == NULL){
				head->next = pVal;
				tail->next = pVal;
			}
			else{
				tail->next->next = pVal;
				tail->next = pVal;
			}				
		}
			
		DataType removeStart() {
			if(tail->next == NULL){
				return DataType();
			}
			else if((head->next) == (tail->next)){
				DataType value_popped = head->next->data;
				delete (head->next);
				head->next = tail;
				tail->next = NULL;
				return value_popped;
			}
				
			else {
				DataType value_popped = head->next->data;
				Node* pHolder = head->next->next;
				delete (head->next);
				head->next = pHolder;
				return value_popped;
			}
			return DataType();
		}	
};


#endif /* SIMPLELIST_H_ */