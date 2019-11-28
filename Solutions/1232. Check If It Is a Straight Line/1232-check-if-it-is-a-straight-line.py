    # LeetCode: 1232. Check If It Is a Straight Line

"""
      Coded by Fatih Cinar
      on November 28th, 2019
"""


class Solution:
    #def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
    def checkStraightLine(self, coordinates):

        differenceInY = coordinates[0][1] - coordinates[1][1]
        # difference in the y's of the first two points
        differenceInX = coordinates[0][0] - coordinates[1][0]
        # difference in the x's of the first two points

        if differenceInX == 0 :
            # we know that if there is no difference is in x
            # this is a vertical line, TAG IT VERTICAL
            isVertical = True
        else:
            # it is not vertical, we can calculate slope
            isVertical = False
            slope = float(differenceInY) / differenceInX
        

        for C in range(1, len(coordinates) - 1): # iterate untill the element before the last one

            differenceInY = coordinates[C][1] - coordinates[C+1][1]
            # find the difference in y's of the two consecutive points
            differenceInX = coordinates[C][0] - coordinates[C+1][0]
            # find the difference in x's of the two consecutive points

            if isVertical:
                # so initially, the line has been tagged as VERTICAL
                if differenceInX == 0:
                    # and if we've gotten a 0 in difference in X
                    # that's what we expected, but keep checking
                    continue
                else:
                    # so if initially the line has been tagged as VERTICAL
                    # but there is A DIFFERENCE IN X
                    # IT'S OVER , NOT A LINE
                    return False
            else:
                # IF THE LINE HAS NOT BEEN TAGGED VERTICAL INITIALLIY
                if differenceInX == 0:
                    # BUT THERE IS NO DIFFERENCE IN X 
                    # this means IT IS NOT A LINE
                    return False
                else:
                    # Calculate slope and compare
                    tempSlope = float(differenceInY) / differenceInX

                    if (slope == tempSlope):
                        # Keep checking other points
                        continue
                    else:
                        # if slopes are different
                        # NOT A STRAIGHT LINE
                        return False
        # if we've not returned false,
        # it means it's a valid line  
        return True


"""
    MAIN FUNCTION

    FOR TESTING PURPOSES
"""

solution = Solution()


coordinates1 = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]

coordinates2 = [[6,7],[3,4],[1,2],[2,3],[5,6],[4,5]]

coordinates3 = [[6,7],[3,4],[1,2],[12,3],[5,6],[4,5]]

coordinates4 = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]

coordinates5 = [[3,4],[8,109]]

coordinates6 = [[1,9],[5,19]]

coordinates7 = [[0,0],[4,1]]

coordinates8 = [[-1,1],[-6,-4],[-6,2],[2,0],[-1,-2],[0,-4]]

coordinates9 = [[-6,1],[-6,109],[-6,101],[-6,0]]

coordinates10 = [[-11,1], [-11,5],[1,1],[2,2],[3,3]]

coordinates11 = [[1,1],[2,2],[3,3],[-11,1], [-11,5],[6,6]]


allCoordinates = [coordinates1, coordinates2, coordinates3,
                  coordinates4, coordinates5, coordinates6, 
                  coordinates7, coordinates8, coordinates9, coordinates10, coordinates11]



for Y in allCoordinates:
    print(Y)
    if solution.checkStraightLine(Y):
        print("LINE")
    else:
        print("NOT A LINE")

