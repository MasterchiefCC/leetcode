#include "mod.h"
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len=temperatures.size();
        vector<int>ret(len,0);
        stack<int>temp;
        for(int a=0; a<len; a++){
            int num=temp.top();
            while(!temp.empty()&&temperatures[a]>temperatures[num]){
                ret[num]=a-num;
                temp.pop();
            }
            temp.push(a);
        }
        return ret;
    }
};