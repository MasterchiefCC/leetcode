class Solution {
    static bool comp(const string &S1, const string &S2){
        if(S1.size()==S2.size()){
            for(int i=0; i<S1.size(); ++i){
                if(S1[i]<S2[i])return true;
                if(S2[i]<S1[i])return false;
            }
            return true;
        }
        return S1.size()>S2.size();
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        string ret;
        sort(d.begin(), d.end(), comp);
        for(int i=0; i<d.size(); ++i){
            bool ok=1;
            int k=0;
            for(int j=0; j<s.size(); ++j){
                if(k<d[i].size()&&s[j]==d[i][k])++k;
            }
            if(k>=d[i].size())return d[i];
        }
        return ret;
    }
};