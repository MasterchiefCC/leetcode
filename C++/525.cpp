#include "mod.h"
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>m_map;
        m_map[0]=-1;
        int cnt=0, ret=0;
        for(int i=0; i<nums.size(); ++i){
            cnt+=(nums[i]<<1)-1;
            map<int, int>::iterator it=m_map.find(cnt);
            if(it==m_map.end()){
                m_map[cnt]=i;
            }
            else{
                ret=max(ret, i-it->second);
            }
        }
        return ret;
    }
};