/*
    LEETCODE 1051 - HEIGHT CHECKER

    coded by Fatih Cinar
    on January 13th, 2020
*/

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        /*
            This function gets an array of people that are in the place
            And figures out how many people are wrongly placed
            in the order in terms of the heights 
        */

        /*
            ALGORITHM
            Duplicate the array
            And then sort the new array
            And then compare two array 
            In order to figure out
            which people are at the wrong place
        */
       
       int wrongPlaces = 0;
       // Number of people who are placed in the order wrong

       vector<int> correctOrdered = heights;
        // Deep copying occurs

       sort(correctOrdered.begin(), correctOrdered.end());

        for(int it = 0; it < correctOrdered.size(); it++){
            if(correctOrdered[it] != heights[it]){
                // This person is at the wrong place
                wrongPlaces++;
                continue;
            }
        }

        return wrongPlaces;

    }
};
