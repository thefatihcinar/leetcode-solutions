    # LeetCode: 168.  Excel Sheet Column Title

"""
    Coded by Fatih Cinar
    on November 26th, 2019
"""

"""
    The problem deals with the interior implementation
    of the excel column sheet title
    The string seen on the screen is associated with a value
    TITLE < -> VALUE
"""
class Solution:
    def convertToTitle(self, number):
        """
            This function will generate string output
            based on the input
            OUTPUT: COLUMN TITLE OF AN EXCEL SHEET
        """

        theTitle = ""

        # we will reduce the number by the factor of 26
        # in every iteration
        while(number > 0):
            # Why reduce the numbre by one?
            number = number - 1
            # Because we are adding to 'A'
            # and 'A' is not ZERO, it is COLUMN 1
            # we take the input, reduce it by one every time and then add to 'A'
            
            # Appending from the left ** THIS IS IMPORANT **
            theTitle = chr(ord('A') + number % 26) + theTitle

            number = int(number/26)
            # divide the number by 26
            # to get to the other characters

        return theTitle

"""

MAIN FUNCTION

FOR TESTING

solution = Solution()

print(type(solution.convertToTitle(4)))

for M in range(1,120):
    print("ID: " + str(M) + "  " + "Title: " + str(solution.convertToTitle(M)))

"""
