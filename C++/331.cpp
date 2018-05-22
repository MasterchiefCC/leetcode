#include "mod.h"
class Solution {
public:
	bool isValidSerialization(string preorder) {
		istringstream in(preorder);
        string temp;
        vector<string>buffer;
        while(getline(in, temp, ','))buffer.push_back(temp);
        int cnt=0;
        for(int i=0; i<buffer.size()-1; ++i){
            if(buffer[i]=="#"){
                --cnt;
                if(cnt==-1)return false;
            }
            else ++cnt;
        }
        return cnt==0 && buffer.back()=="#";
	}
};