#include "mod.h"

class Solution {
private:
static bool myComp(pair<int, int>p1, pair<int, int>p2){
    if(p1.first==p2.first)return p1.second<p2.second;
    else return p1.first>p2.first;
}
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), myComp);
        vector<pair<int, int>> ret;
        for(int a=0; a<people.size(); a++){
            ret.insert(ret.begin()+people[a].second, people[a]);
        }
        return ret;
    }
};