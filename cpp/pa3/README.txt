/**********************************************************************
 *  readme.txt
 **********************************************************************/

Name: Tushar JAIN
Nickname or English name: Tushar
Major: BSc. Economics and Finance
Course: COMP 2012H
Email address: tjain@connect.ust.hk
Programming assignment #: 3
OS: OSX El Capitan 10.11
Compiler: g++ 4.2.1
Hours spent: 20

/**********************************************************************
 *  List whatever help (if any) that you received.
 **********************************************************************/
I have sought help from the following people: N/A
I have read the following books: N/A
I have consulted the following websites: N/A

The work included in this program is all my own work (Y/N): Y

/**********************************************************************
 *  Explain your overall approach and the unique features of your program
 **********************************************************************/
The program allows you to use a Matrix ADT. The default matrix is of size 0x0.
You can enter rows and columns to construct a Matrix of the specified size.
You can also create a Matrix using the copy constructor, which creates a deep
copy. You can also assign one Matrix to another, which deletes the old matrix
if the size of the two matrices don't match before copying the values.

You can get the rows, columns and the element at the specified index. The
transpose function switches the rows and the columns. The mul function
multiplies two matrices but returns a 0 matrix if their sizes don't match.
The printMatrix function prints the matrix. The identity function gives an
identity matrix of the same size, given that the matrix is a square matrix.
The inverse function uses the determinant, cofactor and minor functions to
find the inverse of the matrix.

The minor function iterates through the matrix and skips the specified row and
column. The determinant function uses the minor function and recursively calls
itself to calculate the determinant. The base case is when there is a 2x2 matrix
left. The cofactor function also uses the minor function to calculate the cofactor
matrix, which can then be used by the inverse function to find the Adjugate.

The program can be compiled using "g++ Matrix.cpp tester.cpp -o Matrix" or the Makefile. The output file is "Matrix", which can be executed using "./Matrix".

/**********************************************************************
 *  Describe any serious problems your program has, or anything which
 *  you have not implemented successfully
 **********************************************************************/
N/A

/**********************************************************************
 *  State the input files you used to test your program
 **********************************************************************/
N/A

/**********************************************************************
 *  Known bugs / limitations of the program
 **********************************************************************/
N/A

/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback
 *  on how much you learned from doing the assignment, whether
 *  you like the assignment or not, and how the assignment may be
 *  improved
 **********************************************************************/
