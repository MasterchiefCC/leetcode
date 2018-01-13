#include "mod.h"

class MapSum {
private:
    vector<pair<string, int>> buffer;
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        for(int a=0; a<buffer.size(); a++){
            if(buffer[a].first==key){
                buffer[a].second=val;
                return;
            }
        }
        pair<string, int> temp(key, val);
        buffer.push_back(temp);
        return;    
    }
    
    int sum(string prefix) {
        int size=prefix.size();
        int len=buffer.size();
        int ret=0;
        for(int a=0; a<len; a++)
            ret+=prefix==(buffer[a].first.substr(0, size))?buffer[a].second:0;
        return ret;
    }
}