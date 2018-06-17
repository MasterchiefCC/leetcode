#include "mod.h"
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.empty())return 0;
        vector<pair<int, double>>buffer(position.size());
        for(int i=0; i<position.size(); ++i){
            double dist=target-position[i];
            double time=dist/speed[i];
            buffer[i]=make_pair(position[i], time);
        }
        sort(buffer.begin(), buffer.end(), comp);
        
        int ret=0, pre=1;
        vector<bool>used(position.size(), false);
        for(int i=used.size()-1; i>=0; --i){
            if(used[i])continue;
            ++ret;
            used[i]=true;
            for(int j=0; j<i; ++j){
                if(buffer[i].second>=buffer[j].second)used[j]=true;
            }
        }
        return ret;
    }
private:
    static bool comp(const pair<int, double>& lhs, const pair<int, double>& rhs){
        return lhs.first<rhs.first;
    }
};


int main(){
    vector<int>pos={0,4,2};
    vector<int>speed={2,1,3};
    Solution test;
    cout<<test.carFleet(10, pos, speed);
}