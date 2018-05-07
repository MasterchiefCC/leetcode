#include "mod.h"
class Solution {
public:
    int myAtoi(string str) {
    long ret = 0;
    int indicator = 1;
    int a=str.find_first_not_of(' '); 
    if(str[a] == '-' || str[a] == '+')
        indicator = (str[a++] == '-')? -1 : 1;
    while(str[a]>='0'&&str[a]<='9') {
        ret = ret*10 + (str[a++]-'0');
        if(ret*indicator >= INT_MAX) return INT_MAX;
        if(ret*indicator <= INT_MIN) return INT_MIN;        
    }
    return ret*indicator;
}
};