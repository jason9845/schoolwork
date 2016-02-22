#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

const char delim[] = "->";
const char eol[] = "null;";
const int MAX = 80;

struct node { // struct for linked list
   char data;
   struct node* next;
};

void push(struct node*& head, char data) { // adds a new node to the linked list
   struct node* newNode = new node;
   newNode->data = data;
   newNode->next = head;
   head = newNode;
}

int main() {
	char filename[]= "input.txt";
	ifstream fp;
	fp.open(filename); // open the input files
	if(!fp.good()){
			cout<<"Fail to open file: "<< filename << endl;
	}
	ofstream file; // open the output file
	file.open("output.txt");

	char buffer[MAX];
	struct node* head = NULL; // pointers for linked list
  struct node* current;

	while(true) {

		fp.getline(buffer, MAX); // store line as an array
    char* token = strtok(buffer, delim); // separte the array on delim
		while(token != NULL && strcmp(token, eol) != 0) {
			push(head, *token); // add elements to the linked list
      token = strtok(NULL, delim);
			}

		while(head != NULL) { // free the space on the heap
			file << head->data << "->";
			current = head->next;
			free(head);
			head = current;
		}

		if(fp.eof()) { // stop when end of file is reached
			break;
		}
		file << "null;" << endl; // output null at the end of each line
	}

	fp.close(); //close the files
	file.close();
	return 0;
}
