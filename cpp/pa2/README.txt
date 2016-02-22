/**********************************************************************
 *  readme.txt
 **********************************************************************/

Name: Tushar JAIN
Nickname or English name: Tushar
Major: BSc. Economics and Finance
Course: COMP 2012H
Email address: tjain@connect.ust.hk
Programming assignment #: 2
OS: OSX Yosemite 10.10.5, Linux 3.10.0 (centos)
Compiler: g++ 4.2.1, gcc 4.8.3
Hours spent: 10

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
I implement the permute function through recursion. The base case if when one
element is left in the array inputted by user. The function swaps each element
successively and calls the recursive function. After the recursion, the cards are
swapped back to their original position. The for loop then swaps the next element
until all the elements have been exhausted.

Repetitions are taken care of by using a while loop. I simply check if the alphabet
has already appeared before incrementing the index of the for loop. If it has appeared,
I use the continue statement and move on to the next element.

The game can be compiled using "g++ permute.cpp -o permute" or the Makefile. The output file is "permute", which can be executed using "./permute".

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
