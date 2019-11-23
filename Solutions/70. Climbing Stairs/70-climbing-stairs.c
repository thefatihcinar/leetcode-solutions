
 // LeetCode : 70. Climbing Stairs


/*
    C

    Coded by Fatih Cinar
    on November 22, 2019 
*/

/*
    ALGORITHM

    1. In While Loop, first deal with all possibilities
        i.e. Find number of one-step and two-steps for each possibility
    2. Then we have to PERMUTE this ones and twos, 
        Using PERMUTATION WITH REPETITION 
        Send number of ones and twos to the permutation with repetition function
    3. And Accumulate all the possibilities with permuted values.

*/



int Simplify(long long theNumber, long long *small);

long long int Factorial(long long int value);

long long int PermutationWithRepetition(long long int repeating1, long long int repeating2);

long long int AllPossibilities(int numberofStairs);




int climbStairs(int n)
{
    long long int number = (long long int) n; 
    // cast it to long long int 
    // because we work with long long int in this example 

    return AllPossibilities(number);
}

int Simplify(long long theNumber, long long *small)
{
    /*
        The basic question is why do we need such a function?
        why simplify when we can directly find factorial of a value
        The reason is int and long long int overflows at some value
        in order NOT to calculate 20! or 40! we need to simplify 
        BECAUSE, it is going to be divided by THE SMALLER ONE!
        so we're simpliying before dividing
    */

   /*
        We are taking small one as a reference because
        there is no need to update it later on 
        in that case, we would need structure or array
        that would not be good
   */

    if (*small == 1)
        // if small one is 0! or 1! , we can't simplify 
        return theNumber;
    else
    {   
        
        long long int firstCase = theNumber;
        // Remember the first case

        for (long long int divider = 2; divider <= firstCase; divider++)
        {
            // basically, start from 2, IF you can divide both 
            // small one and the number by that number 
            // divide as much as you can , and keep finding and simplying

            while (theNumber % divider == 0 && *small % divider == 0)
            {
                theNumber = theNumber / divider;
                *small = *small / divider;
            }
        }

        return theNumber;
        // smaller one has already been simplified since it has been taken as a reference
        // and return number 
    }
}

long long int Factorial(long long int value)
{
    /*
        Factorial function,
        but it returns long long int 
        because the number is extremely big
    */

    if (value == 0)
    {
        return 1;
    }
    else
    {
        long long int sum = 1;

        while (value > 0)
        {
            sum = sum * value;
            value--;
        }

        return sum;
    }
}

long long int PermutationWithRepetition(long long int repeating1, long long int repeating2)
{
    /*
        This part is going to be different than Python
        Since Python internally handles overflow cases, and C/C++ does not 
    */

    long long int repeatingAll = repeating1 + repeating2;

    // Find which is BIGGER

    long long int biggerOne;
    long long int smallerOne;

    if (repeating1 >= repeating2)
    {
        biggerOne = repeating1;
        smallerOne = repeating2;
    }
    else
    {
        biggerOne = repeating2;
        smallerOne = repeating1;
    }

    // WE CAN'T CALCUALTE THE FACTORIAL OF ALL OBJECTS 
    // AND WE CAN'T CALCULATE THE FACTORIAL OF THE BIGGER ONE
    // WE ARE GOING TO SIMPIFY THE FACTORIAL OF ALL WITH THE BIGGER ON 

    smallerOne = Factorial(smallerOne);
    // You have to calculate the smaller one  Small!


    long long int result = 1;

    long long int temp = repeatingAll;
    // repeatingAll means ALL! 
    // and remember this

    while (repeatingAll > biggerOne)
    {
        temp = repeatingAll;
        temp = Simplify(temp, &smallerOne);
        // simplify temp with smaller one and than accumulate
        result *= temp;
        repeatingAll--;
    }
    // We do not want to do this
    // and we cant' do this
    // result = Factorial(repeatingAll) / (Factorial(repeating1) * Factorial(repeating2));

    long long int payda = smallerOne;

    result = result / payda;

    // an OVERFLOW GUARD CAN BE ADDED BELOW WITH ASSERT
    //assert(result > 0);


    return result;
}

long long int AllPossibilities(int numberofStairs)
{
    /*
        Calculate all the possibilities that one person can take 
        based on permutation with repetition 
        return LONG LONG INT because there is more than 
        a trillion possiblities
    */

    long long int allPossiblity = 0;

    int numberofOne;
    int numberofTwo;

    numberofOne = numberofStairs;
    numberofTwo = 0;

    while (numberofOne >= 0)
    {

        allPossiblity += PermutationWithRepetition(numberofOne, numberofTwo);

        numberofOne -= 2;

        numberofTwo += 1;
    }

    return allPossiblity;
}