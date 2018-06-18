#include "mod.h"
class Solution {
public:
    int hIndex(vector<int>& citations) {
    //     int len=citations.size();
    //     for(int i=len; i>0; --i){
    //         if(citations[len-i]>=i)return i;
    //     }
    //     return 0;
    // }

        int left=0, right=citations.size()-1, len=citations.size();
        while(left<=right){
            int mid=left+(right-left)/2;
            if(citations[mid]==len-mid)return len-mid;
            else if(citations[mid]>len-mid)right=mid-1;
            else left=mid+1;
        }
        return len-left;
    }
};