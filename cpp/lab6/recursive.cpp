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

void RecursiveReverse(struct node** headRef) {
  struct node* first;
  struct node* rest;

  if (*headRef == NULL) return;
  first = *headRef;
	rest = first->next;
  if (rest == NULL) return;

  RecursiveReverse(&rest);

  first->next->next = first;
  first->next = NULL;
  *headRef = rest;
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
  struct node* current; struct node* tail;

	while(true) {

		fp.getline(buffer, MAX); // store line as an array
    char* token = strtok(buffer, delim); // separte the array on delim

		if((token != NULL && strcmp(token, eol) != 0)) {
      // deal with the special case when head points to null
			push(head, *token); tail = head;
			token = strtok(NULL, delim);
		}
		while(token != NULL && strcmp(token, eol) != 0) {
			push(tail->next, *token); // add elements to the linked list
			tail = tail->next;
      token = strtok(NULL, delim);
			}

		tail = NULL;
    RecursiveReverse(&head);

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
