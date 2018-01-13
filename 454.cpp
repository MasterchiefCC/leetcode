#include"mod.h"
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ret=0;
        map<int, int>cnt;
        for(int a=0; a<A.size(); a++){
            for(int b=0; b<B.size(); b++){
                int buffer=A[a]+B[b];
                map<int,int>::iterator mit=cnt.find(buffer);
                mit==cnt.end()?cnt[buffer]=1:mit->second++;
            }
        }
        for(int c=0; c<C.size(); c++){
            for(int d=0; d<D.size(); d++){
                int buffer=-1*(C[c]+D[d]);
                map<int, int>::iterator mit=cnt.find(buffer);
                ret+=mit!=cnt.end()?mit->second:0;
            }
        }
        return ret;
    }
};