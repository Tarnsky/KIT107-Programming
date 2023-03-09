/*
 * Assignment 1
 * filename: AssigOne 121
 * @author <<Christian Poyo 509778 & Ted Krimmer 532970>>
 * @version <<24/03/21>>
 * 
 * Program to calculate all firing solutions in order of greatest distance 
 * from Doomsville to the least distance from Doomsville and to save the
 * Goners who live there.
 */

public class AssigOne121
{
    public static void main(String []args)
    {
        final int FIRE = 65;  //required charge time to fire
        int charge = 0;  //laser's charge time
        int temp = 0;  //temporary int used for calculating movement time in seconds
        
        /* Creating Time objects: missileTime
         * Setting up the launch time 
         */
        Time missileTime; //new time object
        missileTime = new Time(12,30); //initialising the new object with launch time

        /* Creating new FiringSolution object for missile
         */
        FiringSolution missile;  //new FiringSoution object
        missile = new FiringSolution();  //initialising new object
        missile.setTime(missileTime);  //setting time object as firingsolution time
        missile.setDegree(0);  //setting launch degrees at Launchtown

        /* iterating through each position (degree) of the missile from Launchtown to
         * Doomsville until a solution is found or it is
         * determined there are no solutions
         */
        while(missile.getDegree() < 179)
        {    
            missileTime.addSeconds(43.635); //adds missile flight time per degree
            missile.setDegree(missile.getDegree() + 1); //adjusts missile degree accordingly
            temp = Math.abs(missile.getDegree() - 90);  //getting the difference of degrees from laser and missile

            double laserSeconds = temp * 35;  //calculating how the laser would need to move to get there
            double missileSeconds =  missile.getDegree() * 43.635;  //calculating how the missile would need to move to get there
            charge += laserSeconds;  //adding charge
            
            /* determining how many seconds the movement of each item would
             * take and, if the laser can get there no later than the missile
             */
            if (laserSeconds <= missileSeconds  && charge >= FIRE)
            {
                missile.setX(missile.getDegree()); //determine the (x) coordinate of impact
                missile.setY(missile.getDegree());  //determine the (y) coordinate of impact
                
                System.out.println(missile.toString());  //create a firing solution of these values
                charge = 0; //resetting charge
                laserSeconds = 0; //resetting laserSeconds
                missileSeconds = 0;  //resetting missileSeconds
            }         
        }
    }
}