/*
    LEETCODE 1344 ANGLE BETWEEN HANDS OF A CLOCK

    coded by Fatih Cinar
    on February 16th, 2020

*/

#include <iostream>

using namespace std;


double angleClock(int hour, int minutes){
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

    double degreeMinuteHand;
    degreeMinuteHand = minutes * 6; 

    double degreeHourHand;
    degreeHourHand = ((hour * 30) % 360 ) + minutes * 0.5;
    // 12 hours means 360 degrees so reduce it 
    // minute / 2; why?
    // because 60 minutes is 30 degrees for 1 hour 
    // so one minute 0.5 degrees

    double differenceInDegrees = degreeMinuteHand - degreeHourHand;

    if(differenceInDegrees < 0){
        // IF NEGATIVE
        // MAKE IT POSITIVE, because it is absolute value
        differenceInDegrees *= -1;
    }

    if (differenceInDegrees > 180){
        // there are two angles 
        // find the smaller one 
        
        differenceInDegrees = 360 - differenceInDegrees;
    }

    return differenceInDegrees;

}


/* TESTING PURPOSES */

int main(){

    cout << "Hour: 4 & Minute 50:" << endl
        << angleClock(4,50) << endl;

    cout << "Hour: 12 & Minute 0:" << endl
         << angleClock(12, 0) << endl;

    cout << "Hour: 3 & Minute 15:" << endl
         << angleClock(3, 15) << endl;

    cout << "Hour: 12 & Minute 30:" << endl
         << angleClock(12, 30) << endl;

    cout << "Hour: 3 & Minute 30:" << endl
         << angleClock(3, 30) << endl;


}
