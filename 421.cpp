#include "mod.h"
class Solution{
    public:
        int findMaximumXOR(vector<int>&nums){
            int mask=0, max=0;
            set<int>MySet;
            int len=nums.size();
            for(int i=31; i>=0; i--){
                mask=mask|(1<<i);
                for(int j=0; j<len; j++){
                    MySet.insert(nums[j]&mask);
                }
                int temp=max|(1<<i);
                for(set<int>::iterator sit=MySet.begin(); sit!=MySet.end(); sit++){
                    if(MySet.find(temp^*sit)!=MySet.end()){
                        max=temp;
                        break;
                    }
                }
                MySet.clear();
            }
            return max;
        }
};