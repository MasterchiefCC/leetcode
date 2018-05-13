#include "mod.h"
class Solution {
    pair<bool, int> helper(const string &equation, int pos){
        bool is_neg=equation[pos]=='-'?true:false;
        pos=equation[pos]=='+'||equation[pos]=='-'?pos+1:pos;
        
        if(equation[pos]=='x')return make_pair(true, is_neg?-1:1);
        
        int cnt=0;
        for(int i=pos; pos<equation.size()&&equation[pos]>='0'&&equation[pos]<='9'; ++pos){
            cnt*=10;
            cnt+=equation[pos]-'0';
        }
        return make_pair(equation[pos]=='x', is_neg==true?-cnt:cnt);
    }
public:
    string solveEquation(string equation) {
        int pos_of_euq=equation.find_first_of('=');
        int x_cnt=0, number_cnt=0;
        for(int i=0; i<equation.size(); ++i){
            if(i==0||equation[i]=='+'||equation[i]=='-'||equation[i]=='='){
                if(equation[i]=='=')++i;
                pair<bool, int> temp=helper(equation, i);
                if(temp.first==true)x_cnt+=i<pos_of_euq?temp.second:-temp.second;
                else number_cnt+=i<pos_of_euq?-temp.second:temp.second;
            }
        }
        if(x_cnt==0&&number_cnt==0)return "Infinite solutions";
        else if(x_cnt==0&&number_cnt!=0)return "No solution";
        else return "x="+to_string(number_cnt/x_cnt);
    }
};