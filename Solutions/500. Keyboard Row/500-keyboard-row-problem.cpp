class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {

        vector<string> results; 
        // This vectors holds 
        // which strings can be written with the chars only one row

        bool result;
        // result for one string - iterating object

        for (int i = 0; i < words.size(); i++)
        {
            result = IsOnlyOneRow(words[i]);

            if (result == true)
            {
                results.push_back(words[i]);
                // if we can do this, just push it to result
            }
            else
            {
                continue;
            }
        }

        return results;
    }

private:
    char MakeSmallcase(char ch);
    int DetermineWhereItBelongs(char ch);
    bool IsOnlyOneRow(string word);
};

char Solution::MakeSmallcase(char ch)
{
    /*
      This function provides the functionality 
      of converting a character to a lowercase character
    */

    if (ch >= 'a' && ch <= 'z')
    {
        // already lowercase
        return ch;
    }
    else
    {
        // if it is uppercase
        return 'a' + (ch - 'A');
    }
}

int Solution::DetermineWhereItBelongs(char ch)
{
    /*
        This function gets a character as an input
        and determines which row that character belongs to in
        the keyboard
    */

    ch = MakeSmallcase(ch); // make all characters lowercase 

    // ROW 1
    char Group1[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    int lengthGroup1 = 10;
    // ROW 2
    char Group2[] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    int lengthGroup2 = 9;
    // ROW 3
    char Group3[] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    int lengthGroup3 = 7;

    for (int i = 0; i < lengthGroup1; i++)
    {
        if (ch == Group1[i])
        {
            
            return 1; // indicate GROUP 1
        }
        else
        {
            continue;
        }
    }

    for (int i = 0; i < lengthGroup2; i++)
    {
        if (ch == Group2[i])
        {

            return 2; // indicate GROUP 2
        }
        else
        {
            continue;
        }
    }

    for (int i = 0; i < lengthGroup3; i++)
    {
        if (ch == Group3[i])
        {

            return 3; // indicate GROUP 3
        }
        else
        {
            continue;
        }
    }

    return 0;
}

bool Solution::IsOnlyOneRow(string word)
{
    /*
        This function gets a string
        and finds out whether or not one person can write
        the entire word with the characters only 
        on one row 
    */

    char firstLetter = word[0]; 

    int theRow = DetermineWhereItBelongs(firstLetter);
    // determine first that where the first letter belongs 
    // i.e. to which row

    bool isOnlyOneRow = true;
    // let's assume that we can write it with chars only on one row

    int iteratorRow;
    for (int i = 1; i < word.size(); i++)
    {
        iteratorRow = DetermineWhereItBelongs(word[i]);
        // find out the row of the temp (iterated-on) character

        if (iteratorRow != theRow)
        {
            // if it is different than the first character's row
            // just break and return
            // this is way more efficient
            isOnlyOneRow = false;
            break;
        }
        else
        {
            // else iterate thru the whole string 
            // make sure they belong to the same row
            continue;
        }
    }

    return isOnlyOneRow;
    // return the result
}
