#include "Matrix.h"

// Constructor: Initialize the matrix to be a rows x cols matrix.
// rows >= 0; cols >= 0
// default is an empty 0 x 0 matrix
// No need to initialize matrix elements
Matrix::Matrix(int rows, int cols) {
	r = rows; c = cols;
	elm = new double*[r];
	for(int i = 0; i < r; i++) {
		elm[i] = new double[c];
	}
}

// Copy constructor
Matrix::Matrix(const Matrix & mt) {
	// create the copy matrix
	r = mt.rows(); c = mt.cols();
	elm = new double*[r];
	for(int i = 0; i < r; i++) {
		elm[i] = new double[c];
	}

	// assign values
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			elm[i][j] = mt.el(i, j);
		}
	}
}

// Destructor for the matrix
Matrix::~Matrix() {
	for(int i = 0; i < r; i++) {
		delete [] elm[i];
	}
	delete [] elm;
}

// Return the number of rows of the matrix
int Matrix::rows() const {
	return r;
}

// Return the number of columns of the matrix
int Matrix::cols() const {
	return c;
}

// Return the (i, j)th element of the matrix
// Precondition: i and j are valid ranges
double & Matrix::el(int i, int j) const {
	assert(i >= 0 && j >= 0 && i < r && j < c);
	return elm[i][j];
}

// Assign and copy all the elements of matrix op to the matrix.
// Resize matrix (allocate space) if necessary
void Matrix::assign(const Matrix & op){
	if(r != op.rows() || c != op.cols()) {
		// free memory
		for(int i = 0; i < r; i++) {
			delete [] elm[i];
		}
		delete [] elm;

		// make the matrix to be of the same size
		r = op.rows(); c = op.cols();
		elm = new double*[r];
		for(int i = 0; i < r; i++) {
			elm[i] = new double[c];
		}
	}

	// assign values
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			elm[i][j] = op.el(i, j);
		}
	}
}

// Return a new matrix which is the product of
// this matrix and matrix op.
// Precondition: valid multiplication with correct rows and columns
Matrix Matrix::mul(const Matrix & op) const {
	if(c != op.rows()) {
		Matrix zero;
		return zero;
	} else {
		Matrix product(r, op.cols());
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < op.cols(); j++) {
				for(int k = 0; k < c; k++) {
					product.el(i, j) += elm[i][k] * op.el(k, j);
				}
			}
		}
		return product;
	}
}

// Return a new matrix which is the transpose of the matrix.
Matrix Matrix::transpose() const {
	Matrix trans(c, r);
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			trans.el(j, i) = elm[i][j];
		}
	}
	return trans;
}

// Return a new matrix which is the inverse of the matrix.
// Return a zero matrix if inverse does not exist
Matrix Matrix::inverse() const{
	double det = this->determinant();
	if(det == 0) {
		Matrix zero;
		return zero;
	} else if(r == 1){ // special case
		Matrix inverse(1, 1);
		inverse.el(0, 0) = 1/elm[0][0];
		return inverse;
	} else {
			Matrix adjoint(this->cofactor().transpose());
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < r; j++) {
					adjoint.el(i, j) /= det;
				}
			}
			return adjoint;
	}
}

// Return a new matrix which the identity matrix of the same size
// Precondition: rows are equal to columns
Matrix Matrix::identity() const{
	if(r !=c) {
		Matrix zero;
		return zero;
	} else {
		Matrix id(r, c);
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(i == j) {
					id.el(i, j) = 1;
				} else {
					id.el(i, j) = 0;
				}
			}
		}
		return id;
	}
}

// Prints the matrix
void Matrix::printMatrix() const{
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cout << elm[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// ignores the parameter row and column and returns the minor matrix
Matrix Matrix::minor(int ignore_r, int ignore_c) const{
	if(r == 1) { // speial case
		Matrix zero;
		return zero;
	}
	Matrix minor(r - 1, c - 1);
	for(int i = 0; i < ignore_r; i++){
		for(int j = 0; j < ignore_c; j++){
			minor.el(i, j) = elm[i][j];
		}
		for(int j = ignore_c + 1; j < c; j++) {
			minor.el(i, j - 1) = elm[i][j];
		}
	}

	for(int i = ignore_r + 1; i < r; i++){
		for(int j = 0; j < ignore_c; j++){
			minor.el(i - 1, j) = elm[i][j];
		}
		for(int j = ignore_c + 1; j < c; j++) {
			minor.el(i - 1, j - 1) = elm[i][j];
		}
	}
	return minor;
}

// Retrurns the determinant of the matrix
double Matrix::determinant() const{
	int det = 0;
	if(r != c) {
	} else if(r == 1) { // special case
		det = elm[0][0];
	} else if(r == 2) { // base case
		det = elm[0][0]*elm[1][1] - elm[1][0]*elm[0][1];
	} else { // recurisively calculate the determinant
		for(int i = 0; i < c; i++) {
			if(i % 2 == 0) {
				det += elm[0][i] * this->minor(0, i).determinant();
			} else {
				det -= elm[0][i] * this->minor(0, i).determinant();
			}
		}
	}
	return det;
}

// returns the cofactor matrix
Matrix Matrix::cofactor() const{
	assert(r == c);
	Matrix cofactor(r, c);
	// special cases when 1x1 or 2x2 matrix
	if(r == 1) {
		cofactor.el(0, 0) = elm[0][0];

	} else if(r == 2) {
		cofactor.el(0, 0) = elm[1][1]; cofactor.el(0, 1) = - 1 * elm[1][0];
		cofactor.el(1, 0) = - 1 * elm[0][1]; cofactor.el(1, 1) = elm[0][0];

	} else {
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if((i + j) % 2 == 0) {
					cofactor.el(i, j) = this->minor(i, j).determinant();
				} else {
					cofactor.el(i, j) = -1 * this->minor(i, j).determinant();
				}
			}
		}
	}
	return cofactor;
}
