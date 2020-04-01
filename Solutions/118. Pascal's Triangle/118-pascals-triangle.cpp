/*
    LEETCODE 118 Pascal's Triangle

    coded by Fatih Cinar
    on April 1st, 2020

*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows){
    /*
        this function will generate the Pascal's triangle 
        up to the rows desired
    */

    vector<vector<int>> theTriangle;
    if(numRows == 0) return theTriangle; // do not add any more

    // ROW 1 
    theTriangle.push_back(vector<int>{1});
    if(numRows == 1) return theTriangle; // do not add any more

    // ROW 2
    theTriangle.push_back(vector<int>{1,1});
    if(numRows == 2) return theTriangle; // do not add any more


    // FOR ROWS 3 to NUMBER_ROWS
    int numberElements; // number of elements in a row
    int sum; // summation of two elements in a row
    for(int row = 3; row <= numRows; row++){

         vector<int> thisRow;
         // we will calculate the elements of this row and keep it in this vector
        
         numberElements = row;
         // number of elements in a row is equal to the in which row we are at
         
         for(int index = 0; index < numberElements; index++){
 
             if (index == 0 || index == numberElements - 1){
                 // if this element is the first element or the last element
                 // put 1 in the vector
                 thisRow.push_back(1);

                 continue;
             }
             else{
                 // if this element in the middle
                 // SUM THE TWO ELEMENTS IN THE ROW ABOVE
                
                sum =  theTriangle[row-2][index-1] + theTriangle[row-2][index];
                // WHY NEGATIVE 2 ??
                // because row does not mean row index 
                // row index is actually row -1 
                // and the row above is row index - 1 so row - 2
                thisRow.push_back(sum); // push the calculation to this row's value

                continue;
             }
         }

        theTriangle.push_back(vector<int>(thisRow));
        // add this row to the triangle

        thisRow.clear();
         
    }

    return theTriangle;
}

void printThePascalsTriangle(vector<vector<int>> theTriangle){
    /*
        this function will print given Pascal's Triangle
        in a Triangular Form
    */

    for(int row = 0; row < theTriangle.size(); row++){

        for(int horizontal = 0; horizontal < theTriangle[row].size() ; horizontal++){

            cout << theTriangle[row][horizontal] << " ";
        }

        cout << endl;
    }
}

void testFunctionality(){
    /*
        this function tests the functionality of the Pascal's Triangle code
    */

    vector<vector<int>> triangle1 = generate(1);

    printThePascalsTriangle(triangle1);

    cout << endl << endl;

      

    vector<vector<int>> triangle2 = generate(2);

    printThePascalsTriangle(triangle2);

    cout << endl << endl;



    vector<vector<int>> triangle3 = generate(4);

    printThePascalsTriangle(triangle3);

      cout << endl << endl;



    vector<vector<int>> triangle4 = generate(6);

    printThePascalsTriangle(triangle4);

    cout << endl << endl;


}

int main(){

    testFunctionality();

    return 0;
}
