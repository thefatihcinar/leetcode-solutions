/*
    LEETCODE 299 - BULLS AND COWS

    coded by Fatih Cinar
    on January 30th, 2020

*/

#include <string>
using namespace std;


int CharToInteger(char number){
    /*
        This function converts a digit 
        a corresponding character
    */
    int value = 0;
    return value + number - '0';
}

string getHint(string secret, string guess){
    /*
        This function gives hint to the other user
        based on the guess of the user and the secret number

    */

    int numberOfBulls = 0; 
    int numberOfCows = 0;

    /*
        This algorithm will count the number of bulls and number of cows

        Counting number of bulls and cows actually will happen at the same time

        O(n) complexity

        Iterate on both strings, if their characters at the same index match
        IT'S BULL

        Regardless, Create a hash table and count how many times a number occurs


    */

    int hashMapRepetitionsOfNumbers[10] = {0}; 
    // how many times a digit is repeated in Secret Number

    int hashMapRepetitionsInGuess[10] = {0};
    // how many times a digit is repeated in Guess

    for(int iter = 0; iter < secret.length(); iter++){

        if(secret[iter] == guess[iter]){
            // if the digits at the same ideces are the same 
            // it's a bull
            numberOfBulls++;
        }
        // but regardless just count

        // in each iteration keep track of how many times each number is repeated
        hashMapRepetitionsOfNumbers[CharToInteger(secret[iter])] += 1;

        hashMapRepetitionsInGuess[CharToInteger(guess[iter])] += 1;
    }

    enum INFO{
        NEVER_OCCURED = 0
    };

    int smaller;
    /*
        Let's assume digit 5 repeats 6 times in one and 11 times in other
        we have to get the smaller one
        because cows is 5 in this example 
    */

    for(int iter = 0; iter < 10; iter++){
        // ITERATE ON THE HASHMAPS

        // and get the information about digits
        
        if (hashMapRepetitionsInGuess[iter] == NEVER_OCCURED || hashMapRepetitionsOfNumbers[iter] == NEVER_OCCURED){
            // if they both have never occured
            // this means this digit has ZERO CONTRIBUTION TO THE NUMBER OF COWS
            continue;
         }
         else{
             // if both are not ZERO
             // i.e. BOTH OF THEM OCCURED AT LEAST ONE TIME
             
             // find the smaller one 
             // i.e. CONTRIBUTION TO THE COWS OF THIS DIGIT

             if(hashMapRepetitionsInGuess[iter] <= hashMapRepetitionsOfNumbers[iter]){
                 smaller = hashMapRepetitionsInGuess[iter];
             }
             else{
                 smaller = hashMapRepetitionsOfNumbers[iter];
             }

             numberOfCows += smaller; // this digit contributes to the number of cows
             
         }

    }

    numberOfCows -= numberOfBulls; 
    // number of bulls also counted while counting number of cows
    // remove it 



    string theHint = "";

    theHint = to_string(numberOfBulls) + "A" + to_string(numberOfCows) + "B";

    return theHint;

    
}
