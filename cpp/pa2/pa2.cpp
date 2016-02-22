#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX_ELEMENTS 10 // maximum elements allowed

inline void swap(int& a, int& b){ // swap two numbers
  int temp = a;
  a = b;
  b = temp;
}

void permute(char [], int, int); // function prototype

int main() {
	char cont = 'C'; // stores to respose to continue
	while(cont == 'C' || cont == 'c') {

		char input_list[MAX_ELEMENTS] = {0}; // initiate a list with null characters
		int array_size; // stores the array size

		cout << "Please input array size (1-10): "; cin >> array_size;
		while(array_size < 1 || array_size > MAX_ELEMENTS) {
			cout << "Invalid input. Please input array size (1-10): ";
			cin >> array_size;
		}

		cout << "Please input array elements: "; // asks to input elements
		for( int i = 0; i < array_size; i++ ) {
			cin >> input_list[i];
		}

		permute(input_list, 0, array_size - 1); // prints the permutations

		cout << "Continue to use this program? (C / c to continue): "; cin >> cont;

	}
	return 0;
}

void permute(char list[], int k, int m){ // finds permutations
	int i;
	if( k == m ){ // base case: only 1 element left
		for( i = 0; i <= m; i++ ){ // prints out the element
			cout << list[ i ];
		}
		cout << endl;
	}
	else {
    for( i = k; i <= m; i++ ){

			// checks repetitions, if the elemnt has been used before, discards its redundant
			int j = k;
			while( j < i && list[ j ] != list[ i ] ) {
				j++;
			}
			if( j < i && list[ j ] == list[ i ] ) {
				continue;
			}

			else {
				swap( list[	k ], list[ i ] ); // swap a[i] as the leading symbol
				permute( list, k + 1, m ); // permute with one less element
				swap( list[	k ], list[ i ] ); // restore back to the original sequence for the next iteration
			}
		}
	}
}
