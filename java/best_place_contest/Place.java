/**
 * This class contains the information (name and number of votes) of each place.
 */

public class Place
{
    //
    // Task 1 - create the attributes
    //
    // This is the name of the place
    String name;
    // This is the number of votes
    int votes;

    // Constructor of the class
    public Place(String placename) {
        //
        // Task 1 - Initialize the name of the place and the number of votes
        // 
        name = placename;
        votes = 0;
    }
    
    // Return the name of the place
    public String getName() {
        //
        // Task 1 - Return the name of the place
        //
        return name;
    }
    
    // Return the number of votes
    public int getVotes() {
        //
        // Task 1 - Return the number of votes
        // 
        return votes;
    }
    
    // The place has been voted for
    public void votedFor() {
        //
        // Task 1 - Add the number of votes by one
        //
        votes = votes + 1;
    }
}
