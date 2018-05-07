#include"mod.h"
// class Solution {
//     vector<int> each_byte(int n){
//         vector<int>buffer;
//         while(n>0){
//             buffer.push_back(n%10);
//             n/=10;
//         }
//         reverse(buffer.begin(), buffer.end());
//         return buffer;
//     }
// public:
//     int monotoneIncreasingDigits(int N) {
//         if(N==0)return 0;
        
//         vector<int> buffer=each_byte(N);
//         if(buffer.size()==1)return buffer[0];
        
//         vector<int>ret(buffer.size(), buffer[0]);
//         bool used=0;
//         for(int i=1; i<buffer.size(); ++i){
//             if(buffer[i]>=ret[i-1])ret[i]=buffer[i];
//             else{
//                 ret[i]=9;
//                 int j;
//                 if(used)continue;
//                 used=1;
//                 for(j=i-1; j>0; --j){
//                     if(--ret[j]>=ret[j-1])break;
//                     else ret[j]=9;
//                 }
//                 if(j==0&&ret[0]>0)--ret[0];
//             }
//         }
//         int res=0;
//         for(int i=0; i<ret.size(); ++i){
//             res*=10;
//             res+=ret[i];
//         }
//         return res;
//     }
// };faster version
class Solution {

public:
    int monotoneIncreasingDigits(int N) {
        if(N==0)return 0;
        
        string str=to_string(N);
        int after_to_9=str.size();
        for(int i=str.size()-1; i>0; --i){
            if(str[i-1]<=str[i])continue;
            --str[i-1];
            after_to_9=i;
        }
        for(int i=after_to_9; i<str.size(); ++i)str[i]='9';
        return stoi(str);
    }
};