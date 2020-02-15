
/*
    LEETCODE 1344 - ANGLE BETWEEN HANDS OF A CLOCK

    coded by Fatih Cinar
    on February 16th, 2020

*/


class Solution {
    
    public double angleClock(int hour, int minutes) {
        /*
            This method calculates the angles difference 
            between HOUR HAND and MINUTE HAND
        */

        /*
        ALGORITHM:
            #   Calculate the angles for each hands from 
                the origin(i.e. 12 o'clock)
            #   1 hour makes 30 degrees
            #   1 minute makes 6 degrees

        */

        double angleHourHand = (hour * 30) % 360 + minutes * 0.5;
        // one hour makes 30 degrees
        // 12 o'clock is 0 degrees, that is why modulues applied
        // 60 minutes is 1 hour and that is 30 degrees
        // so 1 minute is 0.5 degree

        double angleMinuteHand = minutes * 6; 
        // 60 minutes is 360 degrees
        // 1 minute is 6 degrees

        double difference = angleHourHand - angleMinuteHand;

        // IF NEGATIVE, MAKE POSITIVE
        if (difference < 0){
            difference *= -1;
        }

        // There are two angles 
        // One is definitely smaller than 180, find it 
        if(difference > 180){
            difference = 360 - difference; // the other angles that completes to 360
        }
        
        
        return difference;
    }
}
