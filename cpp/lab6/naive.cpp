#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

struct node {
   char data;
   struct node* next;
};

void push(struct node*& head, char data) {
   struct node* newNode = new node;
   newNode->data = data;
   newNode->next = head;
   head = newNode;
}

int main() {
	char filename[]= "input.txt";
	ifstream fp;
	fp.open(filename); //Open the files
	if(!fp.good()){
		cout<<"Fail to open file: "<< filename << endl;
	}
	ofstream file;
	file.open("output.txt");

	char ch;
	struct node* head = NULL; struct node* current;

	while(true) {
		while(true) {
			fp >> ch;
			if (ch == '-' || ch == '>') {
				continue;
			} else if(ch == 'n') {
				fp.ignore(4); break;
			} else {
				push(head, ch);
			}
		}
		while(head != NULL) {
			file << head->data << "->";
			current = head->next;
			free(head);
			head = current;
		}
		if(fp.eof()) {
			break;
		}
		file << "null;\n";
	}

	fp.close(); //close the file
	file.close();
	return 0;
}
