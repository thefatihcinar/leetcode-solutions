/*
    LEETCODE 12 - INTEGER TO ROMAN

    coded by Fatih Cinar
    on March 9th, 2020
*/


#include <iostream>
#include <vector>
using namespace std;

string getRomanCounterpart(int singleValue);
    /*
        This function gets an integer number
        and returns its Roman equivalent
    */

string integerToRoman(int value);
    /*
        This function gets an integer value
        and returns the number in Roman Alphabet
    */


enum Values
{
    I = 1,
    IV = 4,
    V = 5,
    IX = 9,
    X = 10,
    XL = 40,
    L = 50,
    XC = 90,
    C = 100,
    CD = 400,
    D = 500,
    CM = 900,
    M = 1000
};

string getRomanCounterpart(int singleValue){
    /*
        This function gets an integer number
        and returns its Roman equivalent
        Only specific ones
        Kind of hash-map
    */

    switch(singleValue){
        case I:
            return "I";
        case IV:
            return "IV";
        case V:
            return "V";
        case IX:
            return "IX";
        case X:
            return "X";
        case XL:
            return "XL";
        case L:
            return "L";
        case XC:
            return "XC";
        case C:
            return "C";
        case CD:
            return "CD";
        case D:
            return "D";
        case CM:
            return "CM";
        case M:
            return "M";
        default:
            return "";

    }


}

string integerToRoman(int value){
    /*
        This function gets an integer value
        and returns the number in Roman Alphabet
    */

    const int numberOfValues = 13;
    // there are 13 values, consider like 13 digits

    int allValues[numberOfValues] =
        {M, CM, D, CD, C, XC, L, XL, X, IX, V, IV, I};
    // We will find these values in integer number
    // BE EXTREMELY CAREFUL
    // add the values to the array in descending order !!

    /*
        ALGORITHM
        # Starting with the biggest values
        # Find each value in the integer number
        # And when you find it, add it to Roman string
    */

    string romanForm = "";

    int valueNow;
    // the value dealing with now

    for (int iterator = 0; iterator < numberOfValues; iterator++)
    {

        valueNow = allValues[iterator];

        // Find the values inside the integer as much as you can
        while (value >= valueNow)
        {
            // Remove one amount from value
            // add the amount to the string
            value -= valueNow;
            romanForm += getRomanCounterpart(valueNow);
        }
    }

    return romanForm;
}

