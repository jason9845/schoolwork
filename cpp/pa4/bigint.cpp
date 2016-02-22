#include <iostream>
#include <cstdlib>
#include <string.h>
#include "bigint.h"
using namespace std;

BigInt::BigInt() {
	sign = '+';
	abs_value.resize(0);
}

BigInt::BigInt(const char *str) {
	from_string(str);
}

BigInt::BigInt(int i) {

	// Get the sign
	if(i < 0) {
		sign = '-';
		i = -1 * i;
	} else {
		sign = '+';
	}

	// Special case
	if(i == 0) {
		abs_value.push_back(0);
	}

	// Get the values to be stored in the vector in reverse order
	while(i != 0) {
		abs_value.push_back(i % 100);
		i /= 100;
	}

	// Reverse the vector to get the right number
	reverse(abs_value.begin(), abs_value.end());
}

// Get the vector
vector<unsigned short> BigInt::get_vector() const{
	vector<unsigned short> vec = abs_value;
	return vec;
}

// Copy constructor
BigInt::BigInt(const BigInt &bi) {
	sign = bi.get_sign();
	abs_value = bi.get_vector();
}

BigInt::~BigInt() {
	abs_value.clear();
}

bool BigInt::from_string(const char *str) {
	// the starting point of the iteration varies if the sign is given
	// the size of the vector varies if the number has odd or even digits
	int i; int len;

	// get the sign of the number and the size of the vector
	if(str[0] == '-' || str[0] == '+') {
		sign = str[0]; i = 1;
		len = (int) strlen(str) - 1;
	} else {
		sign = '+'; i = 0;
		len = (int) strlen(str);
	}

	bool not_done = true; // for special case
	while(str[i] != '\0') {
		// check if each charachter is a number
		if(!isdigit(str[i])) {
			abs_value.resize(0);
			return false;
		}

		// if odd number of digits, the first value in the vector is only one digit
		if (len % 2 != 0 && not_done) {
			abs_value.push_back(str[i] - '0');
			i++; not_done = false;
		} else {
			abs_value.push_back((str[i] - '0') * 10 + str[i + 1] - '0');
			i += 2;
		}
	}

	return true;
}

// removes unecessory zeros
void BigInt::remove_zeros() {
	while(abs_value.front() == 0) {
		abs_value.erase(abs_value.begin());
	}
}

void BigInt::to_string(char *str) {

	// Make sure that the array is empty
	for(int x = 0; x < 1024; x++) {
		str[x] = '\0';
	}

	// Cases according to the sign
	// i is the index of the vector element which is being written
	// x is a helper variable, which helps decide where the digit will be stored
	int x = 0; int i = 0;
	if(abs_value.at(0) < 10 && sign == '+') {
		str[0] = '0' + abs_value.at(0); i = 1;
	} else if(abs_value.at(0) > 9 && sign == '+') {
	} else if(abs_value.at(0) < 10 && sign == '-') {
		str[0] = '-'; str[1] = '0' + abs_value.at(0);
		x = 1; i = 1;
	} else {
		x = 1; str[0] = '-';
	}
	// Iteration to write the string
	for(; i < abs_value.size(); i++) {
		unsigned short num = abs_value.at(i);
		for(int j = 1; j >= 0; j--) {
			str[i + j + x] = '0' + num % 10;
			num /= 10;
		}
		x++;
	}
}

char BigInt::get_sign() const{
	return sign;
}

// Helper function for addition
BigInt BigInt::add(const BigInt & bi) const{
	// this->abs_value is longer than that of bi
	BigInt result;

	vector<unsigned short>::const_iterator rit = abs_value.end() - 1;
	vector<unsigned short>::const_iterator ritb = bi.abs_value.end() - 1;

	unsigned short carry_over = 0;
	while(ritb >= bi.abs_value.begin()) {
		unsigned short to_add = *rit + *ritb + carry_over;
		if(to_add < 100) {
			result.abs_value.push_back(to_add);
			carry_over = 0;
		} else {
			result.abs_value.push_back(to_add % 100);
			carry_over = 1;
		}
		rit--; ritb--;
	}

	while(rit >= abs_value.begin()) {
		unsigned short to_add = *rit + carry_over;
		if(to_add < 100) {
			result.abs_value.push_back(to_add);
			carry_over = 0;
		} else {
			result.abs_value.push_back(to_add % 100);
			carry_over = 1;
		}
		rit--;
	}

	if(carry_over == 1) {
		result.abs_value.push_back(1);
	}

	reverse(result.abs_value.begin(), result.abs_value.end());
	result.remove_zeros();
	return result;
}

BigInt BigInt::operator+(const BigInt &bi) const {
	BigInt result;

	if(sign == bi.sign) {
		if(compare_mag(bi)) {
			result = this->add(bi);
		} else {
			result = bi.add(*this);
		}
		result.sign = sign;
	} else {
		if(compare_mag(bi)) {
			result = this->subtract(bi);
			result.sign = sign;
		} else {
			result = bi.subtract(*this);
			result.sign = bi.sign;
		}
	}
	return result;
}

BigInt BigInt::operator+(int i) const {
	BigInt bi(i);
	return (*this + bi);
}

// Helper function for subtraction
BigInt BigInt::subtract(const BigInt &bi) const{
	// this->abs_value is larger than that of bi
	BigInt result;

	vector<unsigned short>::const_iterator rit = abs_value.end() - 1;
	vector<unsigned short>::const_iterator ritb = bi.abs_value.end() - 1;

	unsigned short give = 0; // takes 0 or 1
	while(ritb >= bi.abs_value.begin()) {
		if(rit == abs_value.begin() && ritb == bi.abs_value.begin() && *rit - *ritb == give) {
			rit--; ritb--;
			break;
		}
		if(*rit < *ritb || (*rit == *ritb && give > 0)) {
			result.abs_value.push_back(*rit + 100 - give - *ritb);
			give = 1;
		} else {
			result.abs_value.push_back(*rit - give - *ritb);
			give = 0;
		}
		rit--; ritb--;
	}

	while(rit > abs_value.begin()) {
		if(give > 0 && *rit == 0) {
			result.abs_value.push_back(*rit + 100 - give);
			give = 1;
		} else {
			result.abs_value.push_back(*rit - give);
			give = 0;
		}
		*rit--;
	}

	if(rit == abs_value.begin()) {
		if(*rit == 1 && give == 1) {
		} else {
			result.abs_value.push_back(*rit - give);
		}
	}

	reverse(result.abs_value.begin(), result.abs_value.end());
	result.remove_zeros();
	return result;
}

// Returns the opposite sign
char BigInt::op_sign() const{
	if (sign == '+') {
		return '-';
	}
	return '+';
}

BigInt BigInt::operator-(const BigInt &bi) const {
	BigInt result;

	if(sign == bi.sign) {
		if(compare_mag(bi)) {
			result = this->subtract(bi);
			result.sign = sign;
		} else {
			result = bi.subtract(*this);
			result.sign = op_sign();
		}
	} else {
		if(compare_mag(bi)) {
			result = this->add(bi);
			result.sign = sign;
		} else {
			result = bi.add(*this);
			result.sign = sign;
		}
	}
	return result;
}

BigInt BigInt::operator-(int i) const {
	BigInt bi(i);
	return (*this - bi);
}

BigInt BigInt::operator%(const BigInt &bi) const {
	BigInt i = 0;
	BigInt q = 0;
	BigInt r = 0;

	q = *this / bi;
	i = q * bi;
	r = this->subtract(i);
	r.sign = sign;
	return r;
}

BigInt BigInt::operator%(int i) const {
	BigInt bi(i);
	return (*this % bi);
}

BigInt BigInt::operator/(const BigInt &bi) const {
	BigInt i = bi;
	BigInt q = 0;

	if(bi.compare_mag(*this) || *this == 0) {
		return q;
	}

	q = 1;

	while(this->compare_mag(i)) {
		i = i.add(bi);
		q++;
	}

	if(i.compare_mag(*this)) {
		q--;
	}

	if(sign == bi.sign) {
		q.sign = '+';
	} else {
		q.sign = '-';
	}
	return q;
}


BigInt BigInt::operator/(int i) const {
	BigInt bi(i);
	return (*this / bi);
}

BigInt BigInt::operator*(const BigInt &bi) const {
	BigInt result = 0;

	for(BigInt i = 0; this->compare_mag(i); i++) {
		if(bi.compare_mag(result)) {
			result = bi.add(result);
		} else {
			result = result.add(bi);
		}
	}

	if(sign == bi.sign) {
		result.sign = '+';
	} else {
		result.sign = '-';
	}
	return result;
}


BigInt BigInt::operator*(int i) const {
	BigInt bi(i);
	return (*this * bi);
}

BigInt & BigInt::operator--() {
	*this = *this - 1;
	return *this;
}

BigInt BigInt::operator--(int i) {
	BigInt result = *this;
	this->operator--();
	return result;
}

BigInt & BigInt::operator++() {
	*this = *this + 1;
	return *this;
}

BigInt BigInt::operator++(int i) {
	BigInt result = *this;
	this->operator++();
	return result;
}


bool BigInt::operator>(int i) const {
	BigInt bi(i);
	return (*this > bi);
}

bool BigInt::operator>=(int i) const {
	BigInt bi(i);
	return (*this >= bi);
}

bool BigInt::operator<(int i) const {
	BigInt bi(i);
	return (*this < bi);
}

bool BigInt::operator<=(int i) const {
	BigInt bi(i);
	return (*this <= bi);
}

bool BigInt::operator==(int i) const {
	BigInt bi(i);
	return (*this == bi);
}

bool BigInt::operator!=(int i) const {
	BigInt bi(i);
	return (*this != bi);
}

bool BigInt::operator>(const BigInt &bi) const {
	if(sign == '+' && bi.sign == '-') {
		return true;
	} else if(sign == '-' && bi.sign == '+') {
		return false;
	} else if(sign == '+' && bi.sign == '+') {
		return(compare_mag(bi));
	} else {
		return(!compare_mag(bi) && (*this != bi));
	}
}

bool BigInt::operator>=(const BigInt &bi) const {
	if (*this == bi || *this > bi) {
		return true;
	}
	return false;
}

bool BigInt::operator<(const BigInt &bi) const {
	return !(*this >= bi);
}

bool BigInt::operator<=(const BigInt &bi) const {
	return !(*this > bi);
}

bool BigInt::operator==(const BigInt &bi) const {
	if(sign != bi.get_sign() || abs_value.size() != bi.abs_value.size()) {
		return false;
	}
	int i = 0;
	while(i < abs_value.size()) {
		if(abs_value.at(i) != bi.abs_value.at(i)) {
			return false;
		}
		i++;
	}
	return true;
}

bool BigInt::operator!=(const BigInt &bi) const {
	return !(*this == bi);
}

BigInt & BigInt::operator=(const BigInt &bi) {
	sign = bi.sign;
	abs_value = bi.abs_value;
	return *this;
}

BigInt & BigInt::operator=(int i) {
	BigInt bi(i);
	*this = bi;
	return *this;
}

BigInt BigInt::operator<<(int i) {
	BigInt result = *this;
	for(int j = 0; j < i; j++) {
		result = 2 * result;
	}
	return result;
}

BigInt BigInt::operator>>(int i) {
	BigInt result = *this;
	for(int j = 0; j < i; j++) {
		result = result / 2;
	}
	if(result.sign == '-' && result % 2 != 0) {
		result = result - 1;
	}
	return result;
}

ostream & operator<<(ostream &out, const BigInt &bi) {
	if(bi.sign == '-') {
		out << '-';
	}
	for(int i = 0; i < bi.abs_value.size(); i++) {
		if(bi.abs_value.at(i) < 10 && i != 0) {
			out << "0";
		}
		out << bi.abs_value.at(i);
	}
	return out;
}

istream & operator>>(istream &in, BigInt &bi) {
	char str[1024] = {'\0'};
	in.get(str, 1024, '\n');

	int i = 0;
	while(str[i] != '\0') {
		i++;
	}

	char real[i + 1];
	for(int j = 0; j < i; j++) {
		real[j] = str[j];
	}
	real[i] = '\0';

	bi.from_string(real);
	return in;
}

// Prints the vector elements
void BigInt::printbi() {
	for(int i = 0; i < abs_value.size(); i++) {
		cout << abs_value.at(i) << " ";
	}
	cout << endl;
}

// Compares the absolute magnitude of the values; true if *this is larger
bool BigInt::compare_mag(const BigInt &bi) const{
	if (abs_value.size() > bi.abs_value.size()) {
		return true;
	} else if(abs_value.size() < bi.abs_value.size()) {
		return false;
	} else {
		for(int i = 0; i < abs_value.size(); i++) {
			if (abs_value.at(i) > bi.abs_value.at(i)) {
				return true;
			} else if(abs_value.at(i) < bi.abs_value.at(i)) {
				return false;
			} else {
				continue; // both are equal
			}
		}
	}
	return false; // both are equal
}

BigInt operator+(int i, const BigInt &bi) {
	BigInt result(i);
	return (result + bi);
}
BigInt operator-(int i, const BigInt &bi) {
	BigInt result(i);
	return (result - bi);
}
BigInt operator*(int i, const BigInt &bi) {
	BigInt result(i);
	return (result * bi);
}
BigInt operator/(int i, const BigInt &bi) {
	BigInt result(i);
	return (result / bi);
}
BigInt operator%(int i, const BigInt &bi) {
	BigInt result(i);
	return (result % bi);
}
