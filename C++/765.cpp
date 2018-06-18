#include "mod.h"
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ret=0;
        for(int i=0; i<row.size()-1; i+=2){
            int second=row[i]%2==0?row[i]+1:row[i]-1;
            if(second==row[i+1])continue;
            ++ret;
            int j=i+1;
            for(; j<row.size(); ++j)if(second==row[j])break;
            swap(row[i+1], row[j]);
        }
        return ret;
    }
};