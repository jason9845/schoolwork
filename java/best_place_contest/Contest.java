/**
 * This class is the main program which counts the votes and make the summary
 * information.
 */
import java.util.Scanner;

public class Contest
{
    // The four candidate places of the contest
    Place[] places = new Place[4];
    
    public Contest() {
        //
        // Task 2 - Initialize the array of the four places
        //
        places[0] = new Place("Library");
        places[1] = new Place("LG7 Lawn Area");
        places[2] = new Place("Lecture Theaters");
        places[3] = new Place("Pier");
    }
    
    // Start the vote counting stage
    public void start() {
        // Prepare a scanner for reading the input
        Scanner scanner = new Scanner(System.in);
        
        int i;
        String choice;
        do {
            // Print the menu
            System.out.println("Please select one of the following:");
            System.out.println();
            
            //
            // Task 2 - Print the choices using a loop
            //
            for (i = 0; i < places.length; i++) {
                System.out.print(i + 1);
                System.out.print(") ");
                System.out.println(places[i].getName());
            }
            
            System.out.println("5) Finish and show result");
            System.out.println();
            System.out.print("Please enter 1, 2, 3, 4 or 5: ");

            // Read the input
            choice = scanner.next();
            
            //
            // Task 2 - Based on the choice add the corresponding vote of the place
            //
            switch (choice) {
                case "1":
                    places[0].votedFor();
                    break;
                case "2":
                    places[1].votedFor();
                    break;
                case "3":
                    places[2].votedFor();
                    break;
                case "4":
                    places[3].votedFor();
                    break;
            }

            System.out.println();
        } while (!choice.equals("5"));
        
        // Show the result page
        showResults();
    }
    
    // Show the result page
    public void showResults() {
        System.out.println("Results");
        System.out.println("------------------------------");
        
        //
        // Task 3 - Find the total number of votes
        //
        int sum = 0;
        int i;
        for (i = 0; i < places.length; i++) {
            sum = sum + places[i].getVotes();
        }

        //
        // Task 3 - Print the number of votes and percentage for each place
        //
        for (i = 0; i < places.length; i++) {
            System.out.print(places[i].getName());
            System.out.print(": ");
            System.out.print(places[i].getVotes());
            System.out.print(" (");
            
            double percentage;
            percentage = (double) places[i].getVotes() / (double) sum;
            percentage = percentage * 100;
            percentage = (int) (percentage * 10) / 10.0;
            
            System.out.print(percentage);
            System.out.println("%)");
        }
    }
    
    // The main method to start the program
    public static void main(String[] args) {
        Contest contest = new Contest();
        contest.start();
    }
}
