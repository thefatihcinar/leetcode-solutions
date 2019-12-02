/*
    coded by Fatih Cinar
    on December 2nd, 2019
*/



class Solution {
public:
    string defangIPaddr(string address) {
        
        string defang; // this will accumulate defang-ip-address
        
        string seperator = "[.]";  // replace . with [.] seperator
        
        for(int i = 0 ; address[i] != '\0' ; i++){ // till the end of the string
            
            if(address[i] == '.'){
       
                defang += seperator;
            }
            else{
            
                defang += address[i];
            }
            
        }
        
        return defang;
        
    }
};
