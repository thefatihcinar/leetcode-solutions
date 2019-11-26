    // LeetCode: 1. Two Sum

/*
        Coded by Fatih Cinar
        on November 26th, 2019
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// return type -> int[2] i.e. int*
int* twoSum(int *nums, int numsSize, int target, int *returnSize)
{   
    /*
        input  int[numsSize]  -> i.e. int*
    */

    int* indices = (int*) malloc(sizeof(int) * 2); // TWO INTEGER INDICES
    // allocating memory for indices to return
    *returnSize = 2; // specifying return size

    /*
        BRUTE FORCE ALGORITHM
        Start from the fist index, till the end of the array
        Search for the forward elements that add up to a target
        O(n^2)
        Memory: O(n) -> the best
    */

    for (int number = 0; number < numsSize; number++)
    {   
        // search for the upcoming elements BRUTE FORCE
        for (int complement = number + 1; complement < numsSize; complement++)
        {
            if (nums[number] + nums[complement] == target)
            {
                indices[0] = number;
                indices[1] = complement;
                return indices;
            }
        }
    }

    // EXIT CASE
    return NULL;
}
