        // LeetCode: 9. Palindrome Number

    /*
        Coded by Fatih Cinar
        on November 25th, 2019
    */

// TR: iki okumali bir sozcuk mu ?
// Will the integer be the same it was reversed?
// Does it read the same backward as forwards?

// "bool" is a typedef!
// true and false are enums ! This is C
bool isPalindrome(int theNumber)
{

    if (theNumber < 0)
    {
        // If negative, since it would have the minus sign
        // that would eliminate its chance to be a palindrome
        return false;
    }
    else
    {

        long int reverse = 0; // reversed of the number
        long int number = (long int) theNumber; // cast it to long int
        // because it do not want it to overflow

        while (number > 0)
        {
            reverse = 10 * reverse + (number % 10);
            // shift one digit left, and then add the new coming digit
            number = number / 10;
            // remove the last digit
        }

        if (reverse == theNumber)
            return true;

        else
            return false;
    }
}
