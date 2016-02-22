#include "Matrix.h"

int main() {

	int rows; int cols;
	cout << "Please enter the number of rows: "; cin >> rows;
	cout << "Please enter the number of colums: "; cin >> cols;
	cout << "Please enter the matrix: " << endl;

	// Initialize te matrix
	Matrix mat(rows, cols);
 	for(int i = 0; i < mat.rows(); i++) {
		for(int j = 0; j < mat.cols(); j++) {
			cin >> mat.el(i, j);
		}
	}
	cout << endl;
	cout << "Matrix" << endl;
	mat.printMatrix();

	// Inverse of the given matrix
	Matrix inverse = mat.inverse();
	cout << "Inverse" << endl;
	inverse.printMatrix();

	// transpose of the given matrix
	Matrix transpose = mat.transpose();
	cout << "Transpose" << endl;
	transpose.printMatrix();

	// multiplied with its inverse
	Matrix multiply = mat.mul(inverse);
	cout << "Multipied with inverse" << endl;
	multiply.printMatrix();

	// a minor matrix
	Matrix minor = mat.minor(1, 1);
	cout << "Minor ignore row 2, column 2" << endl;
	minor.printMatrix();

	// the cofactor matrix
	Matrix cofactor = mat.cofactor();
	cout << "Cofactor" << endl;
	cofactor.printMatrix();

	// the determinant
	int det = mat.determinant();
	cout << "Determinant\n" << det << endl;

	return 0;
}
