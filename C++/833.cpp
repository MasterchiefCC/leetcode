#include"mod.h"

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<replacement>buffer;
        for(int i=0; i<indexes.size(); ++i)buffer.push_back(replacement(indexes[i], sources[i], targets[i]));
        sort(buffer.begin(), buffer.end(), m_comp);
        int cur_i=0;
        string ret;
        
        for(int i=0; i<S.size();){
            if(cur_i<buffer.size()&&i==buffer[cur_i].index){
                const replacement &temp=buffer[cur_i];
                if(temp.index+temp.source.size()<=S.size()&&S.substr(temp.index, temp.source.size())==temp.source){
                    ret+=temp.target;
                    i+=temp.source.size();
                }
                else{
                    ret+=S.substr(temp.index, temp.source.size());
                    i+=temp.source.size();
                }
                ++cur_i;
            }
            else{
                ret+=S[i];
                ++i;
            }
        }
        return ret;
    }
private:
    struct replacement{
        int index;
        string source;
        string target;
        replacement(int index, string source, string target):index(index), source(source), target(target){}
    };
    static bool m_comp(const replacement& R1, const replacement& R2){
        return R1.index<R2.index;
    }
};