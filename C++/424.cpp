class Solution {
public:
    int characterReplacement(string s, int k) {
        int len=s.size(), ret=0, maxCnt=0, start=0;
        vector<int>buffer(26, 0);
        for(int i=0; i<len; ++i){
            maxCnt=max(maxCnt, ++buffer[s[i]-'A']);
            while(i-start+1-maxCnt>k){
                --buffer[s[start]-'A'];
                ++start;
            }
            ret=max(ret, i-start+1);
        }
        return ret;
    }
};