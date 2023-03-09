/**
 * Class for Firing Solution
 * filename: FiringSolution
 * ADT Implmentation for KIT107 Assignment 1
 * @author Julian Dermoudy and <<Christian Poyo 509778 & Ted Krimmer 532970>>
 * @version <<24/03/21>>
 * 
 * Getters and Setters for Private variables of FiringSolution class
 */

import java.text.DecimalFormat;

public class FiringSolution implements FiringSolutionInterface
{
    private static final DecimalFormat FMT=new DecimalFormat("###0.000");
    
    private Time time;
    private int degree;
    private double x;
    private double y;
    
    /* getter's & setter's for each instance variables above along with a 
     * toString to print out FiringSolution object
     */
    
    public void setTime(Time t)
    {
        this.time = t; 
    }
    
    public Time getTime()
    {
        return this.time;
    }
    
    public void setDegree(int d)
    {
        this.degree = d;
    }
    
    public int getDegree()
    {
        return this.degree;
    }
    
    public void setX(double x)
    {
        double r = Math.toRadians(x);
        this.x = 5000*Math.cos(r);
        this.x = Math.round(this.x *1000.0)/1000.0;
    }
    
    public double getX()
    {
        return this.x;
    }

    public void setY(double y)
    {
        double r = Math.toRadians(y);
        this.y = 50*Math.sin(r);
        this.y = Math.round(this.y *1000.0)/1000.0;
    }
    
    public double getY()
    {
        
        return this.y;
    }
    
    public String toString()
    {
        return "At time " +getTime()+ ", fire at " +getDegree()+ " degrees to impact missle at ("+FMT.format(this.x)+", "+FMT.format(this.y)+")";
    }
}