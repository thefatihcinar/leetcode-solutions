
    # LeetCode : 70. Climbing Stairs

"""
    PYTHON

    Coded by Fatih Cinar
    on November 22, 2019 
"""

"""
    ALGORITHM

    1. In While Loop, first deal with all possibilities
        i.e. Find number of one-step and two-steps for each possibility
    2. Then we have to PERMUTE this ones and twos, 
        Using PERMUTATION WITH REPETITION 
        Send number of ones and twos to the permutation with repetition function
    3. And Accumulate all the possibilities with permuted values.

"""

import math

class Solution:
    
    def PermutationWithRepetition(self,repeating1, repeating2):
        # calculating the permutation with repetition 
        
        repeatingAll = repeating1 + repeating2
        # totally, how many objects 
        
        result = math.factorial(repeatingAll) / (math.factorial(repeating1) * math.factorial(repeating2))
        # the basic idea of permutation with repetition

        return result
    
    def AllPossibilities(self,numberofStairs):
        
        allPossibility = 0
        
        numberofOne = numberofStairs
        # start Examining possibilities with numberofones = numberofstairs
        # this means that for the first possiblity lets assume that he/she took
        # steps one-step to the finish
        numberofTwo = 0
        # and none two-steps

        # and now evaluate all possiblities
        while(numberofOne >= 0):
            
            allPossibility += self.PermutationWithRepetition(numberofOne, numberofTwo)
            
            numberofOne -= 2
            # in the other possiblity, instead of two one-step, we'll take one two-step
            numberofTwo += 1
        
        return int(allPossibility)
    
    def climbStairs(self, n: int) -> int:
        
        return self.AllPossibilities(n)
       
