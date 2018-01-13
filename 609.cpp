#include "mod.h"
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths){
        map<string, pair<string, int>> mmap;
        vector<vector<string>>ret;
        unsigned int len=paths.size();
        for(int a=0; a<len; a++){
            int space_Pos=paths[a].find_first_of(' ');
            string path=paths[a].substr(0,space_Pos);

            while(space_Pos!=string::npos){
                int left_bra=paths[a].find_first_of('(', space_Pos+1);
                int right_bra=paths[a].find_first_of(')', left_bra+1);
                string fileName=paths[a].substr(space_Pos+1, left_bra-space_Pos-1);
                string content=paths[a].substr(left_bra+1, right_bra-left_bra-1);
                map<string, pair<string, int>>::iterator mit=mmap.find(content);
                if(mit!=mmap.end()){
                    if(mit->second.second==-1){
                        mit->second.second=ret.size();
                        ret.resize(ret.size()+1);
                        ret[mit->second.second].push_back(mit->second.first);
                    }
                    ret[mit->second.second].push_back(path+"/"+fileName);
                }
                else mmap[content]=make_pair(path+"/"+fileName, -1);
                space_Pos=paths[a].find_first_of(' ', right_bra+1);
            }
        }
        return ret;
    }
};
int main(){
    vector<string>path;
    path.resize(4);
    path[0]="root/a 1.txt(abcd) 2.txt(efgh)";
    path[1]="root/c 3.txt(abcd)";
    path[2]="root/c/d 4.txt(efgh)";
    path[3]="root 4.txt(efgh)";
    Solution a;
    vector<vector<string>>ret =a.findDuplicate(path);




    return 0;
}