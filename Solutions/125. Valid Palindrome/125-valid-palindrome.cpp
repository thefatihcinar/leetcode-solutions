/*
    LEETCODE 125 - VALID PALINDROME

    coded by Fatih Cinar
    on February 1st, 2020
*/

#include <iostream>
#include <string>

using namespace std;

char Lowercase(char aCharacter){
    /*
        This function gets a character
        and makes is a lowercase character 
        for ease of comparison
    */

    if( aCharacter >= 'A' && aCharacter <= 'Z'){
        // an uppercase character
        return 'a' + (aCharacter - 'A');
    }
    else{
        return aCharacter;
    }
}

string FromCharacterToString(char singleCharacter){
    /*
        This function gets a single character
        and converts it to a single-sized string
    */

    string converted = "0";

    converted[0] = singleCharacter;

    return converted;
}

string ConvertToRawFormat(string aSentence){
    /*
        This function gets a sentence or a word
        and removes all non-alphanumeric characters
        and converts the sentence to RAW FORMAT
    */

    // all characters must be lowercased for ease of comparison

    string theRawFormat = "";

    // iterate on the string to eliminate non-alphanumeric characters
    // and to make every character lowercase

    char charIterator;
    
    bool isAlphaNumeric; // a flag that show whether the iterator character is 
    // an alphanumeric character or not

    for(int iter = 0 ; iter < aSentence.size(); iter++){

        charIterator = aSentence[iter]; // a character iterator

        charIterator = Lowercase(charIterator); // make it lowercase always

        isAlphaNumeric = charIterator >= 'a' && charIterator <= 'z' || 
                         charIterator >= '0' && charIterator <= '9';

        if(isAlphaNumeric){
            // if this character that we iterate on
            // is an alphanumeric character 
            // add this character to the raw string
            theRawFormat += FromCharacterToString(charIterator);
        }
        else{
            continue;
        }
    }

    return theRawFormat;

}

bool isPalindrome(string s){
    /*
        This function gets a string
        and figures out whether this given string 
        is a palindrome string or not
    */

    // initially we have to convert the string to raw format

    string theRawFormat = ConvertToRawFormat(s);

    // TWO POINTERS = TWO ITERATORS
    // to figure out whether palindrome or not

    int HALF_THE_STRING = theRawFormat.size() / 2;

    int END = theRawFormat.size() - 1; // the last element (index) in the string

    bool isItPalindrome = true; // assume it is palindrome

    for(int iter = 0; iter < HALF_THE_STRING; iter++){
        // iterate on the first half of the string
        // and compare this first half with the other half

        if(theRawFormat[iter] == theRawFormat[END-iter]){
            continue;
        }
        else{
            isItPalindrome = false;
            break;
        }
    } 

    return isItPalindrome;

}
