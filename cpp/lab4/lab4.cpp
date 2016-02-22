#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

bool checkinterleavin(const char s1[], const char s2[], const char s3[]) {
	if(*s3 + *s1 + *s2 == 0) {
		return true;
	} else if(*s1 == *s3 || *s2 == *s3) {
		if(checkinterleavin(s1+1, s2, s3+1)) {
			return checkinterleavin(s1+1, s2, s3+1);
		} else {
			return checkinterleavin(s1, s2+1, s3+1);
		}
	} else {
		return false;
	}
}

void checkinterleaving(const char s1[], const char s2[], const char s3[]) {
	if(checkinterleavin(s1, s2, s3)) {
		cout << "True" << endl;
	} else {
		cout << "False" << endl;
	}
}

int main() {
	char s1[] = "aabcc";
	char s2[] = "bbdcca";
	char s3[] = "aabbdcbccac"; // aadbbbaccc
	checkinterleaving(s1, s2, s3);
	checkinterleaving("XXY", "XXZ", "XXZXXXY");
	checkinterleaving("XY" ,"WZ" ,"WZXY");
	checkinterleaving("XY", "X", "XXY");
	checkinterleaving("YX", "X", "XXY");
	checkinterleaving("XXY", "XXZ", "XXXXZY");
	return 0;
}
