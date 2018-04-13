#include"mod.h"

class Solution {
public:
    string originalDigits(string s) {
        string ret;
        string name[3][3];
        name[0][0]="one";
        name[0][1]="two";
        name[0][2]="six";

        name[1][0]="four";
        name[1][1]="five";
        name[1][2]="nine";

        name[2][0]="thrid";
        name[2][1]="seven";
        name[2][2]="eight";

        int name_int[]={1,2,6,4,5,9,3,7,8};
        int index=0;
        map<set<char>, int>buffer[3];
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                set<char>temp;
                for(int k=0; k<name[i][j].size(); ++k)temp.insert(name[i][j][k]);
                buffer[i][temp]=name_int[index++];
            }
        }

        int start=0;
        for(int i=2; i<s.size(); ++i){
            int len=i-start;
            index=(i+1)%3;
            set<char>temp;
            for(int j=start; j<=i; ++j)temp.insert(s[j]);
            int cnt=buffer[index][temp];
            ret+=to_string(cnt);
        }
        return ret;
    }
};