/**********************************************************************
 *  readme.txt
 **********************************************************************/

Name: Tushar JAIN
Nickname or English name: Tushar
Major: BSc. Economics and Finance
Course: COMP 2012H
Email address: tjain@connect.ust.hk
Programming assignment #: 4
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
Constructor:
from integer: takes 2 integers at a time and pushes them into the vector.
 Reverses the vector before exiting to store the right values.

Functions:
1. from_string: the size of the vector would vary depending on the number
  of digits and the sign of the number. This function takes into account all
  the cases by choosing the right index to iterate from in order to store the
  vector. If it finds out that any value provided is not a number, it clears the
  vector and exits.

2. to_string: Initializes the array to be empty. Chooses the write index to
  start writing the numbers from. Iterates through each of the vector elements
  to write each digit one by one.

Helper Functions:
1. print_bi: prints out the vector elements one by one

2. add: the object this function is passed to is assumed to be greater than the
  parameter object. Adds number just like numbers are added in base 10 by
  storing carry over value, which takes either 1 or 0. It iterates from the end
  of both the vectors until the beginning index of the smaller BigIng is reached.
  From then onwards, iterates until the beginning of the larger BigInt.

3. subtract: the object this function is passed to is assumed to be greater than the
  parameter object. Iterates in the similar fashion as the add function and if the
  element of the larger number being subtracted is smaller, takes the carry over
  (referred to as give in the function) from the next element.

4. compare_mag: compares the absolute value of both the numbers, by checking the
  size first. If the sizes match, iterates through both the vectors and returns
  false if the parameter is larger, which breaks the loop. If it reaches the end,
  false is returned, implying that the numbers are equal.

5. remove_zeros: removes unnecessary zeros that might have accumulated at the
  front of the resulting vector during computation. Used by the basic
  helper functions (add and subtract) that take BigInt as parameters. There is no
  need to pass this to any other function because other functions that change the
  value of the vector utilize these helper functions.

Operator overloading:
1. +: makes use of the add helper function. Compares the absolute value of both
 the numbers and changes parameters based on which one is larger. Then it assigns
 the sign appropriately.

2. -: works the same way as +. Utilizes the helper function, subtract.

3. *: loops to add successively

4. /: loops and increases the quotient by one until divisor times quotient
  becomes more than or equal to the dividend. If they were equal, adds one to
  the quotient.

5. %: uses / and subtracts the answer from the dividend

These need to be implemented on for BigInt parameter. If the parameter is int, a
separate overloading function is used, which simply converts the int to BigInt
and then calls the one of the appropriate functions described above.

6. right bitwise shift: divides by 2 successively

7. left bitwise shift: multiplies by 2 successively

8. ostream: loops through the vector and outputs the elements one by one. If
  the number was less than 10, outputs a zero before to get the right number.

9. istream: gets the input in an array. Uses from_string to convert the input
  to a BigInt.

10. comparison: only > and == need tot be implemented, which can be used to
  derive other comparison operators. Both first compare the size and the sign
  of the BigInts. If the size is the same, == compares all the values one by
  one and returns false as soon as it spots a number mismatch. While, > uses
  the helper function, compare_mag.

The program can be compiled using "g++ bigint.cpp main.cpp -o bigint" or the
Makefile. The output file is "bigint", which can be executed using "./bigint".

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
