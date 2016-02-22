#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string delim = "->";
const string eol = "null;";

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

	string s;
	struct node* head = NULL; struct node* current;

	while(true) {
		getline(fp, s);
		while(s != eol && !fp.eof()) {
			string token = s.substr(0, s.find(delim));
			push(head, token[0]);
			s.erase(0, s.find(delim) + delim.length());
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
		file << "null;" << endl;
	}

	fp.close(); //close the file
	file.close();
	return 0;
}
