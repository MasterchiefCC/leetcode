#include "mod.h"

class Solution{
	bool isOk(vector<vector<bool>>&buffer, int x, int y){
		int len=buffer.size();
		for(int a=0; a<len; a++){
			if(buffer[x][a]||buffer[a][y])return false;
		}
		int arr[8]={1,-1,1,-1,1,-1,-1,1};
		for(int a=1; a<=len; a++){
			for(int b=0; b<4; b++){
				int m_x=x+a*arr[b];
				int m_y=y+a*arr[b+4];
				if(m_x>=0&&m_y>=0&&m_x<len&&m_y<len&&buffer[m_x][m_y])return false;
			}
		}
		return true;
	}
	int helper(vector<vector<bool>>buffer, int row){
		int ret=0, len=buffer[0].size();
		if(row>=len)return 1;

		for(int a=0; a<len; a++){
			if(isOk(buffer, row, a)){
				buffer[row][a]=true;
				ret+=helper(buffer, row+1);
				buffer[row][a]=false;
			}
		}
		return ret;
	}
public:
	int totalNQueens(int n){
		if(n==0)return 1;
		vector<vector<bool>>buffer(n, vector<bool>(n,0));
		int ret=helper(buffer, 0);
		return ret;
	}
};