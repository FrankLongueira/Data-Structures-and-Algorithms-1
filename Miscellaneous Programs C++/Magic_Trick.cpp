// Magic Trick by Frank Longueira

#include <iostream>
#include<unistd.h>
using namespace std;


int main() {
	
	int cards[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
	
	cout << endl;
	cout << "Please pick a number between 1 - 21 & do not say it out loud." << endl;
	usleep(5000000); 
	cout << "Ready for me to guess it? Let's begin!" << endl;
	usleep(3000000);
	cout << endl;
	
	for(int i = 0; i < 3; i++){
		int column1[7] = {};
		int column2[7] = {};
		int column3[7] = {};
		int col1 = 0;
		int col2 = 0;
		int col3 = 0;
		int pick = 0;
	
		for( int i = 0; i < 21; i++ ) {
			if((i % 3) == 0) {
				cout << cards[i] << "              " << flush;
				column1[col1] = cards[i];
				col1++;
			}
			else if ((i % 3) == 1) {
				cout << cards[i] << "              " << flush;
				column2[col2] = cards[i];
				col2++;
			}
			else {
				cout << cards[i] << "              " << flush;
				column3[col3] = cards[i];
				col3++;
				cout << endl;
	
			}
		}
		cout << endl;
		cout << "Which column is your number in? Please select either 1, 2, or 3 >>> " << flush;
		cin >> pick;
		cout << endl;
			
		if(pick == 1) {
			copy(column2, column2 + 7, cards);
			copy(column1, column1 + 7, cards + 7);
			copy(column3, column3 + 7, cards + 14);
		}
		else if(pick == 2) {
			copy(column3, column3 + 7, cards);
			copy(column2, column2 + 7, cards + 7);
			copy(column1, column1 + 7, cards + 14);
		}
		else {
			copy(column2, column2 + 7, cards);
			copy(column3, column3 + 7, cards + 7);
			copy(column1, column1 + 7, cards + 14);
		}


	}
	
	cout << "Hahaha that was too easy... Your number is obviously: " << cards[10] << "!" << endl;
	cout << endl;

	
	return 0;
}

