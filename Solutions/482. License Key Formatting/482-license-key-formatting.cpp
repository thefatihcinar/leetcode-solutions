/*
    LEETCODE - 482 LICENCE KEY FORMATTING

    coded by Fatih Cinar
    on January 28th, 2020
*/

#include <string>
#include <iostream>

using namespace std;

char toUppercase(char cnvrt);
    /*
        This function gets a character and 
        converts it to an uppercase character
        always
    */

string CharToString(char addThis);
    /*
        This function gets a single character
        and converts it to a string
    */

string ConvertToRawFormat(string licenceKey);
    /*
        This function gets a LICENCE-KEY
        and removes dashes and uppercases all characters
    */

string SplitIntoParts(string rawLicenceKey, int lengthOfOnePart);
    /*
        This function gets a RAW LICENCE KEY, and a length of one part
        and then SPLITS THE RAW LICENCE KEY INTO parts 
        with the given LENGTH
        and returns new splitted licence key
    */



char toUppercase(char cnvrt)
{
    /*
        This function gets a character and 
        converts it to an uppercase character
        always
    */

    if (cnvrt >= 'a' && cnvrt <= 'z')
    {
        // if it is a LOWERCASE CHARACTER
        return 'A' + (cnvrt - 'a');
    }
    else
    {
        // it might be UPPERCASE, do not do anything
        // it might be another character, do not do anything
        return cnvrt;
    }
}

string CharToString(char addThis)
{
    /*
        This function gets a single character
        and converts it to a string
    */

    string converted = "a";
    converted[0] = addThis;

    return converted;
}

string ConvertToRawFormat(string licenceKey)
{
    /*
        This function gets a LICENCE-KEY
        and removes dashes and uppercases all characters
    */

    string newRawLicenceKey;

    enum INFORMATION
    {
        DASH = '-',
        STRING_TERMINATION = '\0'
    };

    int iterator = 0;
    while (licenceKey[iterator] != STRING_TERMINATION)
    {

        if (licenceKey[iterator] == DASH)
        {
            iterator++;
            continue;
        }
        else
        {
            char Uppercased = toUppercase(licenceKey[iterator]);
            newRawLicenceKey.append(CharToString(Uppercased));

            iterator++;
            if (licenceKey[iterator] == STRING_TERMINATION)
            {
                break;
            }
            continue;
        }
    }

    return newRawLicenceKey;
}

string SplitIntoParts(string anyLicenceKey, int lengthOfOnePart)
{
    /*
        This function gets a LICENCE KEY, and a length of one part
        and then SPLITS THE RAW LICENCE KEY INTO parts 
        with the given LENGTH
        and returns new splitted licence key
    */

    string rawLicenceKey = ConvertToRawFormat(anyLicenceKey);

    string newLicenceKey = ""; // new formatted licence key

    bool hasFirstPartDone = false;
    // a FLAG that show whether the first part of the
    // licence key has been created or not
    // because  length of the first part is probably
    // different then the other parts of the licence key

    int iterator = 0;
    int inner_iterator;

    
    int lengthOfFirstPart = rawLicenceKey.length() % lengthOfOnePart;
    // Lengtht of the first part is the remainder after the licence key has been
    // splitted into NumberOfParts

    enum INFO
    {
        EQUALLY_SPLITTED_PARTS = 0,
        DASH = '-',
        EMPTY = 0
    };

    if (rawLicenceKey.length() == EMPTY){
        // if RAW LICENCE KEY is empty, do not do anything
        return newLicenceKey;
    }

    while (iterator <= rawLicenceKey.length())
    {
        if (!hasFirstPartDone)
        {
            // Let's create the first part of the Licence Key
            if (lengthOfFirstPart == EQUALLY_SPLITTED_PARTS)
            {
                // if this licence key can be split equally
                lengthOfFirstPart = lengthOfOnePart;
                // length of first part is no different than other parts
            }
            for (inner_iterator = iterator; inner_iterator < lengthOfFirstPart; inner_iterator++)
            {
                // copy the elements for the first part
                newLicenceKey.append(CharToString(rawLicenceKey[inner_iterator]));
            }
            newLicenceKey.append(CharToString(DASH));

            hasFirstPartDone = true;

            iterator = lengthOfFirstPart;

            continue;
        }
        else
        {
            // FIRST PART IS CREATED SUCCESSFULLY
            // NOW OTHER PARTS
            for (inner_iterator = 0; inner_iterator < lengthOfOnePart; inner_iterator++)
            {
                // Copy the elements from Raw String for this part only
                newLicenceKey.append(CharToString(rawLicenceKey[iterator + inner_iterator]));
            }

            iterator += lengthOfOnePart;

            if (iterator == rawLicenceKey.length())
            {
                // do not put another dash
                return newLicenceKey;
            }
            else
            {
                // put a dash
                newLicenceKey.append(CharToString(DASH));
            }

            continue;
        }
    }

    return newLicenceKey;
}
