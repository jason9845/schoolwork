/*
 * bigint.h
 */

#ifndef BIGINT_H_
#define BIGINT_H_

#include <vector>

using namespace std;

class BigInt {

  public:
    BigInt();
    BigInt(const char *str);
    BigInt(int i);
    BigInt(const BigInt &bi);
    ~BigInt();

    /* #### You need to implement from_string(const char*) and to_string(char*) methods. #### */
    /**
     * Method: void from_string(const char *str)
     * Description:
     * 		from_string method will read the number from str.
     * 		If str is valid, it will be parsed and stored into sign and storage, and then return true. Otherwise, false will be returned.
     */
    bool from_string(const char *str);

    /**
     * Method: void to_string(const char *str)
     * Description:
     * 		to_string method will output the current number to str.
     */
    void to_string(char *str);

    /* #### Please add your overloading methods below. #### */

    BigInt operator+(const BigInt &) const;
    BigInt operator-(const BigInt &) const;
    BigInt operator*(const BigInt &) const;
    BigInt operator/(const BigInt &) const;
    BigInt operator%(const BigInt &) const;
    BigInt operator+(int) const;
    BigInt operator-(int) const;
    BigInt operator*(int) const;
    BigInt operator/(int) const;
    BigInt operator%(int) const;
    BigInt & operator++();			// Pre-fix
    BigInt operator++(int);			// Post-fix
    BigInt & operator--();			// Pre-fix
    BigInt operator--(int);			// Post-fix

    BigInt & operator=(const BigInt &);
    BigInt & operator=(int);

    bool operator>(int) const;
    bool operator>=(int) const;
    bool operator<(int) const;
    bool operator<=(int) const;
    bool operator==(int) const;
    bool operator!=(int) const;
    bool operator>(const BigInt &) const;
    bool operator>=(const BigInt &) const;
    bool operator<(const BigInt &) const;
    bool operator<=(const BigInt &) const;
    bool operator==(const BigInt &) const;
    bool operator!=(const BigInt &) const;

    BigInt operator<<(int);
    BigInt operator>>(int);

    friend ostream & operator<<(ostream &, const BigInt &);
    friend istream & operator>>(istream &, BigInt &);

    // Helper functions
    void printbi();
    vector<unsigned short> get_vector() const;
    char get_sign() const;
    char op_sign() const;
    BigInt add(const BigInt &) const;
    BigInt subtract(const BigInt &) const;
    bool compare_mag(const BigInt &) const;
    void remove_zeros();

  private:
    vector<unsigned short> abs_value;
    char sign;

};

BigInt operator+(int, const BigInt &);
BigInt operator-(int, const BigInt &);
BigInt operator*(int, const BigInt &);
BigInt operator/(int, const BigInt &);
BigInt operator%(int, const BigInt &);

#endif /* BIGINT_H_ */
