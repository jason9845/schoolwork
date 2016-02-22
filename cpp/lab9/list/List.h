#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

class List {
private:
	struct Node {
		string str;
		Node* ptrNext;
		Node* ptrPrev;
	};
	Node* m_Head; // pointer to the head of the linked list
	Node* m_Tail; // pointer to the tail of the linked list

public:
	List();
	~List();
	void Print();
	void PrintReverse();
  bool Insert(string str);

  //ToDo:  implement this function to return the number of node from the head station
  // return -1 when cannot find the distance between str and the head
	int Access(string str);
	int AccessIgnoreCase(string str);
};

#endif
