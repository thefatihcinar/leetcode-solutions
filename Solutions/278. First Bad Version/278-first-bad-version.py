"""
    LEETCODE 278 - FIRST BAD VERSION

    coded by Fatih Cinar
    on January 13th, 2020
"""

# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):


class Solution:
    def recFindFirstBadVersion(self, low, high):
        """
            This method will figure out 
            the first bad version using Binary Search Algorimthm
            RECURSIVE IMPLEMENTATION
        """

        middle = int((low + high) / 2)

        if(high == low + 1): 
            # EXIT CASE 
            # if high is only one greater than low 
            # this means that high has been diagnosed as BAD Before
            # so HIGH IS THE FIRST BAD VERSION
            return high
        elif(isBadVersion(middle)):
            # if the middle element is BAD 
            # do not further search successor version of the middle
            return self.recFindFirstBadVersion(low, middle)

        else:
            # if the middle elemeent is CLEAN
            # do not search for the previous versions 
            # because they are also clean
            return self.recFindFirstBadVersion(middle, high)

    def firstBadVersion(self, numberOfVersions):
        """
        :type numberOfVersions: int
        :rtype: int
        """

        # for low we pass 0
        return self.recFindFirstBadVersion(0, numberOfVersions)
