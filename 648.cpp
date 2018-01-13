#include "mod.h"
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        sentence.push_back(' ');
        vector<string>buffer;
        int index=0;
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i]==' '){
                buffer.push_back(sentence.substr(index, i-index));
                index=i+1;
            }
        }
        for(int i=0; i<buffer.size(); i++){
            for(int j=0; j<dict.size(); j++){
                if(dict[j].size()>buffer[i].size())continue;
                if(buffer[i].substr(0, dict[j].size())==dict[j]){
                    buffer[i]=dict[j];
                }
            }
        }
        string ret;
        for(int i=0; i<buffer.size(); i++){
            ret+=buffer[i]+' ';
        }
        ret.pop_back();
        return ret;
    }
};