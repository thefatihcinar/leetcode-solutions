/*
    LEETCODE 278 FIRST BAD VERSION

    coded by Fatih Cinar
    on January 13th, 2020
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int numberOfVersions)
    {
        /* 
            This function will find out 
            Where the first error occured
            while creating the versions
        */

         /*
            ALGORITHM
            1. One algorithm is of course Brute Force
               Check all versions starting from 1 to N
               This would take O(N) time 
            2. We do not need to check this in O(N)
               We can find out in Logarithmic time O(log N)
               If you find a version randomly and know that 
               it is a clean version, the version before that version are also clean
               And if you find a version that is BAD, the version after
               that version are also BAD 
               BINARY SEARCH 
         */

        long int low = 0; // start from 0 
        long int high = numberOfVersions; // Limit
        long int middle = (low + high) / 2; // this is the middle

        // At the last iteration
        // the difference between low and high will be 1 
        // so middle will always be equal to the low at the EXIT CASE
        while(low != middle){
            if(isBadVersion(middle)){
                // It the randomly chosen version is bad version
                // all the successor versions are also bad
                // do not search for them
                high = middle;
                middle = (low + high) / 2;
                continue;
            }
            else{
                // The randomly chosen version is CLEAN
                // So all the previous ones also clean do not search for them
                low = middle;
                middle = (low + high) / 2;
                continue;
            }
        }

        // at exit case 
        // high is one greater than low
        // and HIGH ONE IS ALWAYS THE FIRST BAD VERSION

        return high;
        
    }
};
