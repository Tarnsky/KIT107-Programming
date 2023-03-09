/**
 * Class for Time
 * ADT implementation for KIT107 Assignment 1
 * filename: Time
 * @author Julian Dermoudy and <<Christian Poyo 509778 & Ted Krimmer 532970>>
 * @version <<24/03/21>>
 * 
 * To set and format time in the Time objects
 */

import java.text.DecimalFormat;

public class Time implements TimeInterface
{
    private static final DecimalFormat FMT=new DecimalFormat("00");
    
    private int hour;
    private int minute;
    private int second;
    
    /**
     * Constructor -- midnight
     * @author Julian Dermoudy
     */
    public Time() //we are guessing the void
    { 
        setTime( 0, 0, 0 ); 
    }
    
    /**
     * Constructor -- to given time
     * @param h new value for hour
     * @param m new value for minute
     * @author Julian Dermoudy
     */
    public Time(int h, int m) //we are guessing the void
    { 
        setTime( h, m, 0); //why is this 0 and not s????
    }
    
    /**
     * Alter hour, minute, and second
     * @param h new value for hour
     * @param m new value for minute
     * @param s new value for second
     * @author Julian Dermoudy
     */
    public void setTime(int h, int m, int s)
    {
        hour = h; 
        minute = m; 
        second = s;
    }
    
    /**
     * Find printable form of time
     * @return String form of time for printing etc.
     * @author Julian Dermoudy
     */
    public String toString()
    { 
        String r;
        
        if (hour >= 12) {
            if (hour == 12)
            {
                r="12";
            }
            else
            {
                r=FMT.format(hour-12);
            }
            r=r+":"+FMT.format(minute)+":"+FMT.format(second)+" PM";
        }
        else {
            if (hour == 0)
            {
                r="12";
            }
            else
            {
                r=FMT.format(hour);
            }
            r=r+":"+FMT.format(minute)+":"+FMT.format(second)+" AM";
        }
        return r;
    }
    
    /**
     * Find printable form of time in 24 hour mode
     * @return String form of time in 24 hour mode for printing etc.
     * @author Julian Dermoudy
     */
    public String toMilitaryString()
    { 
        return FMT.format(hour)+ ":"+FMT.format(minute)+ ":" + FMT.format(second);
    }
    
    /**
     * Determine whether two Time values are equal
     * @param that second Time value
     * @return boolean true if times are equal, false otherwise
     * @author Julian Dermoudy
     */
    public boolean equals(Time that)
    {
        return ((this.hour == that.hour) && (this.minute == that.minute) && (this.second == that.second));
    }
    
    /* 
     * Adding the whole number portion of the double value to the time object;
     */
    public void addSeconds(double s) 
    { 
        this.second += (s); 
        while (this.second >= 60) 
        {
            this.second = Math.abs(60 - this.second);
            this.minute++;
            
            while (this.minute >= 60)
            {
                this.minute = Math.abs(60 - this.minute);
                this.hour++;
                
                while(this.hour >= 25)
                {
                    this.hour = 1;
                }
            }
        }
    }
}