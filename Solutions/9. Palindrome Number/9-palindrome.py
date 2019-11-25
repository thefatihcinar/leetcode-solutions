    # LeetCode: 9. Palindrome Number

    # Coded by Fatih Cinar
    # on November 25th, 2019



# TR: iki okumali bir sozcuk mu ?
# Will the integer be the same it was reversed?
# Does it read the same backward as forwards?
def isPalindrome(x):
    
    if x < 0:
        # If negative, since it would have the minus sign
        # that would eliminate its chance to be a palindrome
        return False
    else:

        # if not negative 
        # do not convert it to string, rather reverse it and then check

        reverse = 0   # reversed of the number
        number = x    # the number

        while(number > 0):

            reverse = 10 * reverse + (number % 10)
            # shift one digit left, and then add the new coming digit

            number = int(number/10)
            # remove the last digit

        if x == reverse:
            return True
        else:
            return False


"""
    ## MAIN FUNCTION

    # It can be used to check the validity of the code

for J in range(-300,300):
    if isPalindrome(J):
        print(J)
    else:
        continue


"""
