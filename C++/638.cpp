#include "mod.h"
class Solution {
    bool check(const vector<int>& offer, const vector<int>needs){
        for(int i=0; i<needs.size(); ++i){
            if(offer[i]>needs[i])return false;
        }
        return true;
    }

    vector<int> decr(const vector<int>& offer, const vector<int>&needs){
        vector<int>needs_cp(needs.size(), 0);
        for(int j=0; j<needs.size(); ++j){
            needs_cp[j]=needs[j]-offer[j];
        }
        return needs_cp;
    }

    int shopping(const vector<int>&price, const vector<vector<int>>& special, vector<int>needs ){
        int cnt=INT_MAX;
        for(int i=0; i<special.size(); ++i){
            if(check(special[i], needs)){
                int temp_cnt=special[i].back()+shopping(price, special, decr(special[i], needs));
                cnt=min(temp_cnt, cnt);
            }
        }
        int temp_cnt=0;
        for(int i=0; i<needs.size(); ++i){
            temp_cnt+=needs[i]*price[i];
        }
        return min(temp_cnt, cnt);
        
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shopping(price, special, needs);
    }
};