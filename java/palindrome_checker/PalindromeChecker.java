/**
 * Exercise for lesson 2 Palindrome Checker
 *
 * This program reads a word, reverses the word and then show whether the word
 * is a Palindrome or not.
 *
 * In this file, you need to finish three tasks:
 * - Reading an Input Word from the User
 * - Finding the Reversed Word
 * - Showing the Result
 */

import java.util.Scanner;

public class PalindromeChecker
{
    /**
     * The main method of the program.
     */
    public static void main(String[] args)
    {
        //
        // Task 1: Prepare a scanner for reading the user input
        // 
        Scanner scanner = new Scanner(System.in);

        // This is the word variable for storing the word entered by the user
        String word = "";

        // This is the reverseWord variable for storing the word in reverse order
        String reversedWord = "";

        do {
            System.out.print("Please enter a word (enter 'bye' to quit the program): ");

            //
            // Task 1: Read a word into the word variable
            // 
            word = scanner.next();


            //
            // Task 1: Turn the word into lower case letters
            // 
            word = word.toLowerCase();
            
            //
            // Task 2: Reverse the order of the word and put it in reversedWord
            //
            int i;
            reversedWord = "";
            for (i = word.length() - 1; i >= 0; i--) {
                reversedWord = reversedWord + word.charAt(i);
            }

            //
            // Task 3: Show the result by checking whether the word is a Palindrome
            //
            if(word.equals(reversedWord)) {
                System.out.println("The word is a Palindrome!");
            }
            else {
                System.out.println("The word is not a Palindrome!");
            }
            
            System.out.println();
        } while (!word.equals("bye"));

        System.out.println("Bye!");
    }
}
