/*
    LEETCODE 13 - ROMAN TO INTEGER
    
    coded by Fatih Cinar
    on March 7th, 2020
*/

#include <iostream>
#include <vector>

using namespace std;

int getValue(char oneDigit);
    /*
        This function returns
        the integer value of one single roman digit
    */

int romanToInteger(string romanNumber);
    /*
        This function converts Roman Number
        into Integer counterpart
    */

void TesterFunction();
    /*
        This functions tests possible values
        for the functionality of the function
    */

int main(){

    TesterFunction();
    
    return 0;
}

int romanToInteger(string romanNumber)
{
    /*
        This function converts Roman Number
        into Integer counterpart
    */

    int length = romanNumber.size();

    int accumulation = 0; // the digits accumulate to this

    if (length == 0)
    {
        // no information is given, 0 year
        return accumulation;
    }

    /*
        ALGORITHM
        # Iterate on each digit
        # Check if the following digit has a greater value or not
        # IF YES, ADD TO THE SUM FOLLOWING_DIGIT - DIGIT_NOW
        # IF NO, ADD TO THE SUM THE VALUE OF THIS DIGIT
    */

    for (int iterator = 0; iterator < length;)
    {
        // cout << "Iterator: " << iterator << endl;

        if (iterator == length - 1)
        {
            // If we are at the last element
            // do not check for the following digit
            // segmentation fault
            accumulation += getValue(romanNumber[iterator]);
            break;
        }
        else
        {
            // First check this
            // if the following digit has greater value than this digit
            // then add the sum of these digits
            // e.g. IV = 5-1  CM = 1000 - 10
            int difference;
            difference = getValue(romanNumber[iterator + 1]) - getValue(romanNumber[iterator]);

        
            if (difference > 0)
            {
                // if the following digit is greater
                // so basically you got the value of
                // the two digits
                accumulation += difference;

                // TWO STEPS UP NOW
                iterator += 2;
            }
            else
            {
                // the digitNow and the followingDigit
                // either has the same value or the following is smaller
                // get the value of this digit
                accumulation += getValue(romanNumber[iterator]);

                // and only ONE STEP UP
                iterator++;
            }
        }
    }

    return accumulation;
}


int getValue(char oneDigit)
{
    /*
        This function returns
        the integer value of one single roman digit
    */

    enum Values
    {
        I = 1,
        V = 5,
        X = 10,
        L = 50,
        C = 100,
        D = 500,
        M = 1000
    };

    switch (oneDigit)
    {

    case 'I':
        return I;
    case 'V':
        return V;
    case 'X':
        return X;
    case 'L':
        return L;
    case 'C':
        return C;
    case 'D':
        return D;
    case 'M':
        return M;
    default:
        //throw "digit not exist";
        return 0;
    }
}



void TesterFunction(){
    /*
        This functions tests possible values
        for the functionality of the function
    */

    vector<string> romanNumbers;
    vector<int> expectedResults;

    // Add values to the vectors
    romanNumbers.push_back("V");
    expectedResults.push_back(5);

    romanNumbers.push_back("III");
    expectedResults.push_back(3);

    romanNumbers.push_back("IV");
    expectedResults.push_back(4);

    romanNumbers.push_back("M");
    expectedResults.push_back(1000);

    romanNumbers.push_back("MM");
    expectedResults.push_back(2000);

    romanNumbers.push_back("DV");
    expectedResults.push_back(505);

    romanNumbers.push_back("MCMXCIV");
    expectedResults.push_back(1994);

    romanNumbers.push_back("MMXX");
    expectedResults.push_back(2020);

    romanNumbers.push_back("LVIII");
    expectedResults.push_back(58);

    romanNumbers.push_back("IX");
    expectedResults.push_back(9);

    romanNumbers.push_back("XII");
    expectedResults.push_back(12);

    romanNumbers.push_back("MCCCXCII");
    expectedResults.push_back(1392);

    romanNumbers.push_back("MMLXXI");
    expectedResults.push_back(2071);


    for(int i = 0; i < romanNumbers.size(); i++){
        
        cout << "Roman: " << romanNumbers[i] << " " 
             << endl
             << "Expected: " << expectedResults[i]
             << " Gotten: " << romanToInteger(romanNumbers[i])
             << endl;

        if (romanToInteger(romanNumbers[i]) == expectedResults[i])
        {
            cout << "Status: " << "CORRECT" << endl;     
        }
        else{
            cout << "Status: " << "ERROR" << endl;  
        }
    }
}
