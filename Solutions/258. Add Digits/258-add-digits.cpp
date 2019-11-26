    // LeetCode: 258. Palindrome Linked List

    /*
        Coded by Fatih Cinar
        on November 26th, 2019
    */

#include <iostream>

using namespace std;

class Solution
{
public:
    int addDigits(int number)
    {
        int result = number;
        // result better be start from number
        // WE WILL MAKE REDUCTIONS ON RESULT EVERY TIME

        
        // MAKE REDUCTIONS UNTIL 0 <= RESULT <= 9
        //i.e. MAKE REDUCTIONS IN DIGITS UNTIL RESULT >= 10
        while(result >= 10){

            result = AccumulateDigits(result);
            // update the result each time
        }

        return result;

    }
private:
    int AccumulateDigits(int number){
        /*
            What this function does is that 
            it just adds the digits up
            ONE TIME 
        */

        int result = 0;

        while(number > 0){
            // make the number smaller each time

            result = result + number % 10;
            // add the last digit

            number /= 10; 
        }

        return result;
    }
};


/* THIS PART IS FOR TESTING */

int main(){

    Solution solution; 

    enum info {length = 14};

    int testCases[length] = {0, 10, 38, 49, 41, 
                        456, 98123, 4923, 441, 
                        11, 2, 5 , 191, 99};

    for(int x = 0; x < length; x++){
        cout << "Number: " << testCases[x] << "\t"
             << "Reduced Digits: " << solution.addDigits(testCases[x]) << endl;
    }



}
