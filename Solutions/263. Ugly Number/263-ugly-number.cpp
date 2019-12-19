/*
    LEETCODE 263 UGLY NUMBER

    coded by Fatih Cinar
    on December 20th, 2019
*/

class Solution
{
public:
    bool isUgly(int number)
    {   
        /*
            This method will determine whether the 
            given number is an UGLY NUMBER or not
        */

        if (number < 0 || number == 0)
        {
            // all negative numbers and 0 are non-ugly numbers
            return false;
        }

        // else if the number is greater or equal to 1

        /* REDUCTION OPERATION */
        while (number % 2 == 0){ number /= 2;}
        // divide the number by 2 3 and 5 as much as possible

        while (number % 3 == 0){ number /= 3;}

        while (number % 5 == 0){ number /= 5;}

        // number is now REDUCED number

        if (number == 1){
            // if the reduced form is 1
            return true;
        }
        else{
            // in this case, it means the number has
            // more dividents other than 2,3 and 5 
            return false;
        }

    }
};
