class Solution {
    static bool myComp(const int &p1, const int &p2){
        return p1>p2;
    }
public:
    int leastBricks(vector<vector<int>>& wall) {
        int row=wall.size();
        if(row==0)return 0;

        int len=0;
        for(int i=0; i<wall[0].size(); ++i)
            len+=wall[0][i];

        map<int, int>buffer;
        bool ok=1;
        for(int i=0; i<wall.size(); ++i){
            int cnt=0;
            if(wall[i].size()!=1)ok=0;
            for(int j=0; j<wall[i].size()-1; ++j){
                cnt+=wall[i][j];
                if(buffer.find(cnt)==buffer.end())buffer[cnt]=1;
                else ++buffer[cnt];
            }
        }
        
        if(ok)return row;
        vector<int>ret;
        for(map<int, int>::iterator mit=buffer.begin(); mit!=buffer.end(); ++mit)
            ret.push_back(mit->second);
        sort(ret.begin(), ret.end(), myComp);
        
        return row-ret[0];
    }
};