    // LeetCode: 7. Reverse Integer

    /*
        Coded by Fatih Cinar
        on November 26th, 2019
    */

#include <climits>
#include <iostream>

/*
    IMPLEMENTATION DETAILS
    Given us an integer encoded by 32 bits
    in the range -2^31 , 2^31 - 1 
    we cant use long , long long 
    If  , WHEN REVERSING, If any kind of overflow occurs, 
    we have to return 0;
    using INT_MAX,  INT_MIN
*/

class Solution
{
public:
    int reverse(int number)
    {
    
        bool isNegative;

        if (number < 0)
        {
            // if the number is NEGATIVE
            isNegative = true;
            if (number == INT_MIN)
                // if the number is THE MINIMUM NUMBER
                // It can't be reversed
                return 0;

            number = number * -1; // Make the number POSITIVE temporarily
        }
        else

            isNegative = false; // if 0 or positive

        
        int reversedNumber = 0;

        // we're always dealing with a positive number
        while (number > 0) // as long as there is any digit to reverse
        {
            if (reversedNumber > INT_MAX / 10)
                // IF before multiplying with 10, 
                // if the reversed number is greater than that 
                // it will overflow, THIS IS THE DETECTION MECHANISM
                return 0;

            reversedNumber = 10 * reversedNumber + number % 10;
            // shift the reversed number by one digit 
            // and add the last digit of the number
            number = number / 10;
            // make the number smaller
        }

        if (isNegative)
            // make the number negative again, IF SO
            reversedNumber *= -1;

        return reversedNumber;
    }
};
