class Solution {
public:
    int magicalString(int n) {
        if(n==0)return 0;
        if(n<3)return 1;
        string buffer="122";
        int pos=2, size=3, ret=1;
        while(size++!=n){
            buffer+=string(buffer[pos++], buffer.back()=='1'?'2':'1');
            if(buffer.back()=='1')ret+=buffer[pos-1];
        }
        return ret;
    }
};