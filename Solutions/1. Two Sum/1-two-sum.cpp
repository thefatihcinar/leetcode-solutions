    // LeetCode: 1. Two Sum

/*
        Coded by Fatih Cinar
        on November 26th, 2019
*/

class Solution
{
public:
    /*
        return type || vector<int> of 2 ||
    */
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /*
            BRUTE FORCE ALGORITHM
            Start from the fist index, till the end of the array
            Search for the forward elements that add up to a target
            O(n^2)
            Memory: O(n) -> the best
        */

        vector<int> indices;
        // the returning vector that show the indices 
        // of the two values that add up to a specific target

        for (int number = 0; number < nums.size(); number++)
        {   
            // Search for the UPCOMING ELEMENTS
            for (int complement = number + 1; complement < nums.size(); complement++)
            {
                if (target == nums[number] + nums[complement])
                {
                    indices.push_back(number);
                    indices.push_back(complement);
                    return indices;
                }
            }
        }

        // EXIT CASE
        return indices;
    }
};
