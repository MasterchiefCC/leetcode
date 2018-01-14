#inclde "mod.h"
class Solution {
    set<set<int>>result;
    void helper(set<int> mySet, const int& k, const int &n, int cur_val){
        if(mySet.size()==k){
            int temp=n-cur_val;
            if(temp<=9&&temp>=1&&mySet.find(temp)==mySet.end()){
                mySet.insert(temp);
                if(result.find(mySet)==result.end()){
                    result.insert(mySet);
                }
            }
        }
        else{
            for(int num=1; num<=9; ++num){
                if(mySet.find(num)==mySet.end()){
                    mySet.insert(num);
                    helper(mySet, k, n, cur_val+num);
                    mySet.erase(num);
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        set<int>temp;
        helper(temp, k-1, n, 0);
        vector<vector<int>> ret(result.size(), vector<int>(k, 0));
        int ret_index=0;
        for(auto sit=result.begin(); sit!=result.end(); (++sit, ++ret_index)){
            int index=0;
            for(auto ssit=sit->begin(); ssit!=sit->end(); (++ssit, ++index)){
                ret[ret_index][index]=*ssit;
            }
        }
        return ret;    
    }
};