#include "mod.h"

class Solution {
    static bool  mySort(pair<char, int>p1, pair<char, int>p2){
        return p1.second>p2.second;
    }
public:
    string frequencySort(string s) {
        map<char, int> mmap;
        int len=s.size();
        for(int a=0; a<len; a++){
            map<char, int>::iterator mit=mmap.find(s[a]);
            if(mit!=mmap.end()){
                mit->second++;
            }
            else {
                mmap[s[a]]=1;
            }
        }
        vector<pair<char, int>> buffer;
        buffer.resize(mmap.size());
        int i=0;
        for(map<char, int>::iterator mit=mmap.begin(); mit!=mmap.end(); mit++){
            buffer[i++]=make_pair(mit->first, mit->second);
        }
        sort(buffer.begin(), buffer.end(), mySort);
        string ret;
        len=buffer.size();
        for(int a=0; a<len; a++){
            string temp(buffer[a].second, buffer[a].first);
            ret+=temp;
        }
        return ret;
    }
};