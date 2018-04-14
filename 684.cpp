#include"mod.h"
class SolutionDFS {
	bool helper(map<int, vector<int>>&buffer, const int &P_0, const int &P_1, const int &used) {
		if (buffer.find(P_0) == buffer.end())return false;
		for (int i = 0; i<buffer[P_0].size(); ++i) {
			if (P_1 == buffer[P_0][i])return true;
			else if (buffer[P_0][i] != used && helper(buffer, buffer[P_0][i], P_1, P_0))return true;
		}
		return false;
	}

public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int>ret;
		map<int, vector<int>>buffer;
		for (int i = 0; i<edges.size(); ++i) {
			if (helper(buffer, edges[i][0], edges[i][1], 0)) {
				ret = edges[i];
				continue;
			}
			else {
				buffer[edges[i][0]].push_back(edges[i][1]);
				buffer[edges[i][1]].push_back(edges[i][0]);
			}
		}

		return ret;
	}
};

class Solution {
	
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ret;
        map<int, int>root;
        for(auto &edge: edges){
            int &x=edge[0];
            int &y=edge[1];
            if(root.find(x)==root.end())root[x]=x;
            if(root.find(y)==root.end())root[y]=y;

            if(root[x]==root[y])
                ret=edge;

            
            int update=root[y];
            for(auto mit=root.begin(); mit!=root.end(); ++mit){
                if(mit->second==update)mit->second=root[x];
            }
        }
        return ret;
	}
};
