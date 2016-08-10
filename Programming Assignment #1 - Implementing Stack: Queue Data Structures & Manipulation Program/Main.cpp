/*  Name: Frank Longueira
	Course: DSA I
	Instructor: Professor Sable
	
	Programming Assignment #1 - Stack/Queue Implementation & Manipulation
	
	Program Description: This program processes the user's input file & performs the requested stack 
	and queue manipulations. During this procedure, the program writes to an output file, specified 
	by the user, describing the processing being done & any errors that occur.
*/

#include "ParsingProcessing.h"
#include "SimpleList.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main() {

	list<SimpleList<int> *> listSLi;
  	list<SimpleList<double> *> listSLd; 	
 	list<SimpleList<string> *> listSLs;
 	
	string input_file;
	string output_file;
	
	welcome(input_file, output_file);
	
	ifstream inputFile(input_file);
	ofstream outputFile(output_file);

 	
	vector<string> commands(3, " ");
	string commandline;
	
	/* The following while-loop processes the input text file line-by-line by calling 
	functions in the various above header files.
	*/
	while (getline(inputFile, commandline)) {
		
		outputFile << "PROCESSING COMMAND: " << commandline << endl;
		
		parse_line(commandline, commands);

		char data_flag = commands[1].at(0);
						
		if( commands[0] == "create" ) {
			switch(data_flag){
				case 'i':
					process_create(listSLi, commands[1], commands[2], outputFile);		
					break;
			
				case 'd':
					process_create(listSLd, commands[1], commands[2], outputFile);
					break;
				
				case 's':
					process_create(listSLs, commands[1], commands[2], outputFile);
					break;
			}
		}
		
		else if( commands[0] == "push" ){
		
			// First, convert value-to-be-pushed from a string to the appropriate data type of the list
			int command2i;
			double command2d;
			if (data_flag == 'i'){
				string_to_int(commands[2], command2i);
			}
			if (data_flag == 'd') {
				string_to_double(commands[2], command2d);

			}

			switch(data_flag){
				case 'i':
					process_push(listSLi, commands[1], command2i, outputFile);		
					break;
			
				case 'd':
					process_push(listSLd, commands[1], command2d, outputFile);
					break;

				case 's':
					process_push(listSLs, commands[1], commands[2], outputFile);
					break;
			}

		}
		
		else{
			switch(data_flag){
				case 'i':
					process_pop(listSLi, commands[1], outputFile);		
					break;
			
				case 'd':
					process_pop(listSLd, commands[1], outputFile);
					break;
					
				case 's':
					process_pop(listSLs, commands[1], outputFile);
					break;
			}
		}
	}
	return 0;
}


				
