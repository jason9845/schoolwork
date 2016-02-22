#include "List.h"

List::List()
{
	m_Head = NULL;
	m_Tail = NULL;
}

List::~List()
{
	m_Tail = NULL;
	Node *ptrTemp;
	while (m_Head != NULL)
	{
		ptrTemp = m_Head;
		m_Head = m_Head->ptrNext;
		delete ptrTemp;
	}
}


void List::Print()
{
	Node *ptrTemp = m_Head;
	while(ptrTemp != NULL)
	{
		cout << ptrTemp->str << "->";
		ptrTemp = ptrTemp->ptrNext;
	}
    cout << "NIL" << endl;
}

void List::PrintReverse() {
	Node *ptrTemp = m_Tail;
	while(ptrTemp != NULL)
	{
		cout << ptrTemp->str << "->";
		ptrTemp = ptrTemp->ptrPrev;
	}
		cout << "NIL" << endl;
}

int List::Access(string str)
{
	if (m_Head == NULL)		// empty list
		return -1;
	else {
		if (m_Head->str == str) {
			return 0;
		}
		else {
      // Assessment
      // To add some code here
			Node *ptrTemp = m_Head;
			int num = 0;
			while(ptrTemp->str != str) {
				num++;
				ptrTemp = ptrTemp->ptrNext;
			}
			return num;
		}
		return -1;
	}
}

int List::AccessIgnoreCase(string str) {
	for(int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}

	if (m_Head == NULL)		// empty list
		return -1;
	else {
		if (m_Head->str == str) {
			return 0;
		}
		else {
			// Assessment
			// To add some code here
			Node *ptrTemp = m_Head;
			string lower = ptrTemp->str;
			for(int i = 0; i < lower.length(); i++) {
				lower[i] = tolower(lower[i]);
			}

			int num = 0;
			while(lower != str) {
				num++;
				ptrTemp = ptrTemp->ptrNext;
				lower = ptrTemp->str;
				for(int i = 0; i < lower.length(); i++) {
					lower[i] = tolower(lower[i]);
				}
			}
			return num;
		}
		return -1;
	}
}

bool List::Insert(string str)
{
	if (str == "q") {
		cerr << "invalid string\n";
		return false;
	}

	if (m_Head == NULL) {	// empty list
		m_Head = new Node;
		m_Head->str = str;
		m_Head->ptrNext = NULL;
		m_Tail = m_Head;
		m_Tail->ptrPrev = NULL;
	}
	else {
		//Create new node
		Node *ptrNew = new Node;
		ptrNew->str = str;
		ptrNew->ptrNext = NULL;
		ptrNew->ptrPrev = NULL;

		Node *ptrTemp = m_Head;
		while (ptrTemp->ptrNext != NULL)
		{
			if (ptrTemp->str == str)	// discard duplicated node
				return false;
			ptrTemp = ptrTemp->ptrNext;
		}
		if (ptrTemp->str == str)	// checking the last node
			return false;

		//Append to last
		ptrTemp->ptrNext = ptrNew;
		ptrNew->ptrPrev = ptrTemp;
		m_Tail = ptrNew;
	}
	return true;
}
