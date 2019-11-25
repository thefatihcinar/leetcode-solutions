    // LeetCode: 9. Palindrome Number

    /*
        Coded by Fatih Cinar
        on November 25th, 2019
    */

// TR: iki okumali bir sozcuk mu ?
// Will the integer be the same it was reversed?
// Does it read the same backward as forwards?
public class Solution {
    public bool IsPalindrome(int theNumber) {
        
        if (theNumber < 0){
            // If negative, since it would have the minus sign
            // that would eliminate its chance to be a palindrome
            return false;
        }
        else{
            // if not negative
            // do not convert it to string, rather reverse it and then check
            long  reversedNumber = 0; // reverse of the number
            long  number = theNumber;
            // we use long 
            
            while(number > 0){

                reversedNumber = reversedNumber * 10 + (number%10);
                // shift one digit left, and then add the new coming digit
                number = number / 10;
                // remove the last digit
            }
            
            if (reversedNumber == theNumber)

                return true;

            else
            
                return false;
        }
        
        
    }
}
