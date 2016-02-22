import greenfoot.*;

/**
 * Write a description of class Bullet here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Bullet extends Actor
{
    /**
     * Act - do whatever the Bullet wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public void act() 
    {
        // Add your action code here.
        move(6);
        if (!getObjectsInRange(20, Rock.class).isEmpty()) {
            Score score = (Score) getWorld().getObjects(Score.class).get(0);
            score.increase();
            Rock rock = (Rock) getObjectsInRange(20, Rock.class).get(0);
            getWorld().removeObject(rock);
            getWorld().removeObject(this);
            return;
        }
        
        World world = getWorld();
        if (getX() < 0 || getX() >= world.getWidth() ||
            getY() < 0 || getY() >= world.getHeight()) {
            world.removeObject(this);
        }
    }    
}
