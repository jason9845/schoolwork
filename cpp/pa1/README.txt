/**********************************************************************
 *  readme.txt                                                   
 **********************************************************************/

Name: Tushar JAIN       
Nickname or English name: Tushar
Major: BSc. Economics and Finance
Course: COMP 2012H
Email address: tjain@connect.ust.hk
Programming assignment #: 1
OS: OSX Yosemite 10.10.5, Linux 3.10.0 (centos)       
Compiler: g++ 4.2.1, gcc 4.8.3  
Hours spent: 24     


/**********************************************************************
 *  List whatever help (if any) that you received.
 **********************************************************************/
I have sought help from the following people: N/A
I have read the following books: ADTs, Data Structures and Problem Solving with C++
I have consulted the following websites: www.cplusplus.com for syntax

The work included in this program is all my own work (Y/N): Y


/**********************************************************************
 *  Explain your overall approach and the unique features of your program
 **********************************************************************/
I have implemented all the requirements for the assignment, a basic working program, split operation,
looping and payment accounting and a dealer who does not draw cards if he is more than 5 points from busting.

I create a loop to ask if the player wants to play again. Each time the player answers yes, 
the loop is executed and a new game starts. If the player wants to play the test case, 
the test deck is created, otherwise a normal deck of cards is generated and shuffled randomly.
Cards are drawn one by one until the player reaches a score of 21 or doesn’t want to draw anymore.
After the cards is drawn from the deck, the index of that card gets -1, which makes sure that the same
card cannot be drawn again. Even indexes store the card value and odd indexes store the type of suit.

To implement the split, I create 4 types of hands, one for each time the player wants to split.
Each hand is dealt with separately using a 2 dimensional array to store each set of cards and a one 
dimensional array to store each score, amount paid and won and card count.

To ensure that Ace can take either 1 or 11, I initially give Ace the value of 11 and keep a count of aces. 
If counting Ace as 11 results in a bust, it is counted as 1 and ace count is reduced by 1 successively.


After the game is over, the dealer draws the cards as long as he is no more than 5 points from busting. 
The result for each type of hand is calculated separately. If the amount won is positive
for that round, the player wins.
  
The game can be compiled using "g++ tjain.cpp -o tjain" or the Makefile. The output file is "tjain", which can
be executed using "./tjain".
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
