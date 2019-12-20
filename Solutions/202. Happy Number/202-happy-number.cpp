/*
    LEETCODE  202  HAPPY NUMBER

    coded by Fatih Cinar
    on December 20th, 2019
*/

class Solution
{
public:
    bool isHappy(int number);

private:
    vector<int> encounteredNumbers;
    bool IsContained(int number);
};

bool Solution::isHappy(int number)
{

    int accumulated = 0; // the sum of squares will be accumulated here

    int lastDigit;

    while (number > 0)
    {

        lastDigit = number % 10; // get the last digit of the number
        accumulated += lastDigit * lastDigit;

        number /= 10; // remove the last digit
    }

    if (accumulated == 1)
    {
        return true;
    }
    else
    {
        if(IsContained(accumulated)){
            // it is a loop, we've seen this number before
            return false;
        }
        else{
            // this is the first see of this number
            encounteredNumbers.push_back(accumulated);
            return isHappy(accumulated);
        }
        
    }
}

bool Solution::IsContained(int number)
{
    /*
        This method will determine whether we've seen this number before
        or not
        LOOP DETERMINER
    */

    for (int iterator = 0; iterator < encounteredNumbers.size(); iterator++){

        if (encounteredNumbers[iterator] == number){
            return true;
        }
        else{
            continue;
        }
    }

    return false;
}
