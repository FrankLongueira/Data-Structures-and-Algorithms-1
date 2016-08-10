#ifndef PARSINGPROCESSING_H_
#define PARSINGPROCESSING_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include "SimpleList.h"
#include "Stack.h"
#include "Queue.h"



/*
Welcomes the user at the command line & asks for names of input and output text files
*/
void welcome(string &input_file, string &output_file){
	cout << endl;
	cout << "Welcome to the Stack/Queue Manipulator!" << endl;
	cout << endl;
	cout << "Please input the name of your input text file >> " << flush;
	cin >> input_file;
	cout << endl;
	cout << "Please input the name of your output text file >> " << flush;
	cin >> output_file;
	cout << endl;
}


/*
Parses a line by whitespace and places the tokens into a vector
*/
void parse_line(const string &commandline, vector<string> &commands, const string &delim = " "){ 
	int start = 0;
	int end = 0;
	int i = 0;
	while(end != string::npos){
		end = commandline.find(delim, start);
		commands[i] = commandline.substr(start, end - start);
		start = end + 1;
		i++;
	}
}



/*
Checks to see if a specific Simplelist exists
*/
template <typename Object>
bool existence(const list<SimpleList<Object> *> &L, const string &name){
	bool exists = false;
	for (typename list<SimpleList<Object> *>::const_iterator itr = L.begin(), end = L.end(); itr != end; ++itr){
		if(name == ((*itr)->getName())){
			exists = true;
			break;
		}
	}
	return exists;
}


/*
Creates a new stack or queue depending on command given & writes to the output file if the name already exists
*/
template <typename Object>
void process_create(list<SimpleList<Object> *> &L, const string &command1, const string &command2, ostream &outputFile){
	bool exists = existence(L, command1);
	if(exists){
		outputFile << "ERROR: This name already exists!" << endl;
	}

	if(exists == false){
		if(command2 == "stack"){
			SimpleList<Object>* pL = new Stack<Object>(command1);
			L.push_front(pL);
		}
		else{
			SimpleList<Object>* pL = new Queue<Object>(command1);
			L.push_front(pL);
		}
	}
}


int string_to_int(const string &input_string, int &input_int){
	stringstream ss;
	ss << input_string;
	ss >> input_int;
	return input_int;
}


double string_to_double(const string &input_string, double &input_double){
	stringstream ss;
	ss << input_string;
	ss >> input_double;
	return input_double;
}


/*
Pushes a value onto the specified Simplelist & writes to the output file if there is an error
*/
template <typename Object>
void process_push(const list<SimpleList<Object> *> &L, const string &command1, const Object &command2, ostream &outputFile){
	bool exists = false;
	for (typename list<SimpleList<Object> *>::const_iterator itr = L.begin(), end = L.end(); itr != end; ++itr){
		if(command1 == ((*itr)->getName())){
			exists = true;
			(*itr)->push(command2);
			break;
		}
	}
	if(exists == false){
		outputFile << "ERROR: This name does not exist!" << endl;
	}
}


/*
Pops a value from the specified Simplelist & writes to the output file the popped value
*/
template <typename Object>
void process_pop(const list<SimpleList<Object> *> &L, const string &command1, ostream &outputFile){
	bool exists = false;
	for (typename list<SimpleList<Object> *>::const_iterator itr = L.begin(), end = L.end(); itr != end; ++itr){
		if(command1 == ((*itr)->getName())){
			exists = true;
			if((*itr)->getEnd() == NULL){
				outputFile << "ERROR: This list is empty!" << endl;
			}
			else{
				outputFile << "Value popped: " << (*itr)->pop() << endl;
			}
			break;
		}
	}
	if(exists == false){
		outputFile << "ERROR: This name does not exist!" << endl;
	}
}



#endif /* PARSINGPROCESSING_H_ */