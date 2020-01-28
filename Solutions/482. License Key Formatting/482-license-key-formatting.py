"""
    LEETCODE - 482 LICENCE KEY FORMATTING

    coded by Fatih Cinar
    on January 28th, 2020
"""

def FormatLicenceKey(anyLicenceKey, lengthOfParts):

    dash = '-'
    
    # Create the new licence key backwards 
    ## indices must start from backward

    backwardsFormattedLicenceKey = ""

    count = 0
    # it is necessary to parse the licence key accordingly

    lengthLicenceKey = len(anyLicenceKey)
    for X in range(lengthLicenceKey-1, -1, -1):
        # iterate from the end to the start 
        if(anyLicenceKey[X] == dash):
            continue

        if(count % lengthOfParts == 0 and count != 0):
            backwardsFormattedLicenceKey += dash

        backwardsFormattedLicenceKey += anyLicenceKey[X]
        count += 1

        

        
    backwardsFormattedLicenceKey = backwardsFormattedLicenceKey.upper()

    formattedLicenceKey = ""

    lengthOfFormattedLicenceKey = len(backwardsFormattedLicenceKey)
    for M in range(lengthOfFormattedLicenceKey-1, -1, -1):
        
        if backwardsFormattedLicenceKey[M] == dash:
            formattedLicenceKey += dash
        else:
            formattedLicenceKey += backwardsFormattedLicenceKey[M]

    return formattedLicenceKey

