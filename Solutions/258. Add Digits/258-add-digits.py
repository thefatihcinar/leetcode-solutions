   # LeetCode: 258. Add Digits

"""
      Coded by Fatih Cinar
      on November 26th, 2019
"""

class Solution:
    def addDigits(self, num):

        result = num  # start from the number
        # and we will make REDUCTIONS 

        # MAKE REDUCTIONS UNTIL  0 <= RESULT <= 9 
        # i.e.  MAKE REDUCTIONS IN DIGITS UNTIL RESULT >= 10
        while(result >= 10):

            result = self.AccumulateDigits(result)
            # sum the digits of the result 
            # update the result 
        
        return int(result)
        # return the updated result 

    # this function does not make reductions 
    # it just adds the digits up ONE TIME 
    def AccumulateDigits(self,number):

        result = 0

        while(number > 0):

            result = result + number % 10;
            number = int(number/10)

        return int(result)


"""

MAIN FUNCTION

    # Testing 

numbers = [0, 10, 38, 49, 41, 456, 98123, 4923, 441, 11, 2, 5, 191, 99]

solution = Solution()

for J in numbers:
    print("number ", J , "   " , solution.addDigits(J))

"""

