#include "mod.h"
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
        if(n==0)return {};
		return dfs(1, n);
	}
private:
	vector<TreeNode*> dfs(int minn, int maxn) {
        if(minn>maxn)return { NULL };
		vector<TreeNode*>ret;
		for (int cur = minn; cur <= maxn; ++cur) {
            for(TreeNode*left:dfs(minn, cur-1)){
                for(TreeNode*right:dfs(cur+1, maxn)){
                    ret.push_back(new TreeNode(cur));
                    ret.back()->left=left;
                    ret.back()->right=right;
                }
            }
        }
		return ret;
	}
};
