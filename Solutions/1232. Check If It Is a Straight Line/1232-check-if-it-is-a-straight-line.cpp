    // LeetCode: 1232. Check If It Is a Straight Line

    /*
        Coded by Fatih Cinar
        on November 28th, 2019
    */

#include <iostream>
#include <vector>

using namespace std;

/*
    ALGORITHM
    1. Get the first two points 
    2. Calculate the differences between X's and Y's
    3. Do not calculate slope 
         >> since slope is just a ratio, we will not this ratio
         >> instead we will use CROSS-MULTIPLICATION
         >> same idea
    4. CROSS-MULTIPLY  
        >> initial_dif_in_y * difference_in_x should be equal to int_if_in_x * diff_in_y
    * THIS IS THE ALGORITHM
*/

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        /*
            This function gets its input as coordinates
            and determines that whether those given coordinates
            create a straight line or not  
        */

        int initDifInY = coordinates[0][1] - coordinates[1][1];
        // initial difference in y's
        int initDifInX = coordinates[0][0] - coordinates[1][0];
        // initial difference in x's

        int differenceInY;
        // difference in y's between the point iterator is at and the initial point
        int differenceInX;
        // difference in x's between the point iterator is at and the initial point

        for(int C = 1; C < coordinates.size() -1 ; C++){

            differenceInY = coordinates[C][1] - coordinates[0][1];
            // difference in y's between the point iterator is at and the initial point
            differenceInX = coordinates[C][0] - coordinates[0][0];
            // difference in x's between the point iterator is at and the initial point

            if(differenceInY * initDifInX != differenceInX * initDifInY){
                // IF THE CROSS MULTIPLICATION IS NOT THE SAME, 
                // MEANS THAT IF THE SLOPES ARE DIFFERENT
                // RETURN ZERO
                return false;
            }
            else{
                // IF CROSS MULTIPLICATION IS SAME
                // I.E. IF THE SLOPES ARE THE SAME
                // CONTINUE CHECKING WITH OTHER POINTS
                continue;
            }
        }

        // if there are two point, 
        // two points always create a straight line
        return true;
    }
};

/*  THIS IS FOR TESTING THE FUNCTION */ 

int main(){

    Solution solution;

    
    vector<vector<int>> coordinates1 = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    vector<vector<int>> coordinates2 = {{6, 7}, {3, 4}, {1, 2}, {2, 3}, {5,6}, {4,5}};
    vector<vector<int>> coordinates3 = {{6, 7}, {3, 4}, {1, 2}, {2, 3}, {5, 6}, {4, 5}};
    vector<vector<int>> coordinates4 = {{-6, 1}, {-6, 109}, {-6, 101}, {-6, 0}};
    vector<vector<int>> coordinates5 = {{1,1}, {2,2}, {3,3}, {-11,1}, {-11,5}, {6,6}};

    vector<vector<vector<int>>> allCoordinates = {coordinates1, coordinates2, coordinates3, coordinates4, coordinates5};

    for(int X = 0; X < allCoordinates.size(); X++){
        
        if (solution.checkStraightLine(allCoordinates[X]))
        {
            cout << "LINE" << endl;
        }
        else
        {
            cout << "NOT A LINE" << endl;
        }
    }

    return 0;
}
