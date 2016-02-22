#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

class Matrix {                          // Matrix class
public:
  explicit Matrix(int rows = 0, int cols = 0); // constructor
  Matrix(const Matrix & mt);           // copy constructor
  ~Matrix(); // destructor
  int rows() const; // return the number of rows of the matrix
  int cols() const; // return the number of columns of the matrix
  double & el(int i, int j) const;           // access (i, j)th element
  void assign(const Matrix & op);       // copy values from op
  Matrix mul(const Matrix & op) const;  // multiplication of matrices
  Matrix transpose() const;             // the transpose of matrix
  Matrix inverse() const;             // the inverse of matrix
// Add your public member functions, if any, in the following
  Matrix identity() const;         // the identity matrix of the same size
  void printMatrix() const;       // prints the matrix
  double determinant() const; // calculates and returns the determinant
  Matrix minor(int ignore_r, int ignore_c) const; // ignores the parameter rows and colums
  Matrix cofactor() const;

private:
	double **elm; // matrix elements
	int r; // number of rows
	int c; // number of columns
// Add your private data members and private member functions,
// if any, in the following
};
