#include "mod.h"

class Solution {
public:
  string complexNumberMultiply(string a, string b ) {  
    int T[6];
    sscanf(a.c_str( ), "%d+%di",  &T[0],  &T[1] ); 
    sscanf(b.c_str( ), "%d+%di",  &T[2],  & T[3] ); 
    T[4] =T[0] * T[2] - T[1] *T[3], T[5] = T[0] * T[3] + T[1] * T[2]; 
    return to_string(T[4] ) + "+" + to_string(T[5]) + "i"; 
    }
}; 


int main( ) {
    Solution a; 



    return 0; 
}