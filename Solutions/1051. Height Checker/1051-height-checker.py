"""
    LEETCODE 1051 - HEIGHT CHECKER

    coded by Fatih Cinar
    on January 13th, 2020
"""

class Solution:
    def heightChecker(self, heights):
        """
            This function gets an array of people that are in the place
            And figures out how many people are wrongly placed
            in the order in terms of the heights 

            input type: heights -> List[int]
            return type: int
        """

        """
            ALGORITHM
            Duplicate the array
            And then sort the new array
            And then compare two array
            In order to figure out
            which people are at the wrong place
        """

        wrongPlaces = 0

        correctOrdered = self.deepCopy(heights)
        correctOrdered.sort()
        # now the new list is sorted in terms of heights

        iterator = 0
        while(iterator < len(correctOrdered)):
            if(correctOrdered[iterator] != heights[iterator]):
                # This means that this person
                # is WRONGLY PLACED
                wrongPlaces += 1
                iterator += 1
                continue
            
            else:
                iterator += 1
                continue
            
        return wrongPlaces

        

    def deepCopy(self,heights):
        """
            This method creates a deep copy of a Python list
            input type : List[int]
            return type: List[int]
        """

        newOne = list()
        
        for I in range(len(heights)):
            # Copy all the elements one-by-one
            # from one list into another
            newOne.append(heights[I])
        
        return newOne
        


