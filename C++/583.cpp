class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size(), len2=word2.size();
		vector<vector<int>>buffer(len1+1, vector<int>(len2+1,0));
		for(int i=0; i<=len1; ++i){
			for(int j=0; j<=len2; ++j){
				if(i==0||j==0)buffer[i][j]=0;
				else if(word1[i-1]==word2[j-1])buffer[i][j]=buffer[i-1][j-1]+1;
				else buffer[i][j]=max(buffer[i-1][j], buffer[i][j-1]);
	    	}
    	}
	return buffer[len1][len2];
    }
};