/*
    LEETCODE 551 - STUDENT ATTANDANCE RECORD I

    coded by Fatih Cinar
    on January 13th, 2020
*/

class Solution
{
public:
    bool checkRecord(string AttandanceRecord);
    /*
        This method will determine whether a student 
        should be rewarded or not based on 
        his/her attandance records
    */
};


bool Solution::checkRecord(string AttandanceRecord){
    /*
        This method will determine whether a student 
        should be rewarded or not based on 
        his/her attandance records
    */

    int numberOfAbsent = 0;  // how many times he/she was absent
    int tempLate = 0; // number of Lates for the L block - temporarily
    bool flagTooMuchLate = false; // FLAG SHOWING TOO MUCH LATE
    bool flagTooMuchAbsent = false; // FLAG SHOWING TOO MUCH ABSENT


    int ite = 0; // iterator
    while (ite < AttandanceRecord.size()){
        // Iterate on the attance records

        if (AttandanceRecord[ite] == 'P'){
            // if he/she was present, keep going
            ite++;
            continue;
        }
        else if (AttandanceRecord[ite] == 'A'){
            // if he was absent 
            // check whether he has been absent before or not

            if(numberOfAbsent == 0){
                // it this is his first absence, no problem
                numberOfAbsent++; // remember this
                
                ite++;
                continue;
            }
            else{
                // if this is his SECOND absence, PUNISH HIM i.e. return false
                numberOfAbsent++;

                flagTooMuchAbsent = true;
                return false;
            }
        }
        else if (AttandanceRecord[ite] == 'L'){
            // If he was late one day
            // Search for CONTINUOUS LATES as further as you can
            // go furthest
            tempLate++;
            ite++;  
            // ONE LATE
            while (AttandanceRecord[ite] == 'L')
            {
                // as long as he was late on upcoming days
                // remember this as well
                tempLate++;
                ite++;
            }

            if(tempLate > 2){
                // IF more than 2 continuous late
                // PUNISH
                tempLate = 0;
                flagTooMuchLate = true;
                return false;
            }
            else{
                // Refresh the tempLate counter to ZERO 
                tempLate = 0;
                // we've already icreased the iterator
                // don't increase again
                continue;
            }
        }
    }

    // if there are no irregularities
    // REWARD HIM/HER
    return true;

}

