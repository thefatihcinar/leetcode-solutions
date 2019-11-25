   // LeetCode: 9. Palindrome Number

/*
    Coded by Fatih Cinar
    on November 25th, 2019
*/


// TR: iki okumali bir sozcuk mu ?
// Will the integer be the same it was reversed?
// Does it read the same backward as forwards?

/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function (x) {

    if (x < 0) {
         // If negative, since it would have the minus sign
        // that would eliminate its chance to be a palindrome
        return false;
    }
    else {
        // if not negative 
        // do not convert it to string, rather reverse it and then check
        let reverse = 0; // reverse of the number
        let number = x;

        while (number > 0) {

            reverse = reverse * 10 + (number % 10) ;
            // shift one digit left, and then add the new coming digit

            number = Math.floor(number / 10);
            // remove the last digit
            // Math.floor removes floating parts 
        }

        if (reverse === x) {

            return true;

        }
        else {

            return false;

        }
    }

};