#include "treemod.h"

class Solution {
    map<int, int>mmap;
    void helper(TreeNode*Node){
        if(Node==NULL)return;
        helper(Node->left);
        helper(Node->right);
        Node->val+=Node->left==NULL?0:Node->left->val;
        Node->val+=Node->right==NULL?0:Node->right->val;
        map<int,int>::iterator mit=mmap.find(Node->val);
        mit==mmap.end()?mmap[Node->val]=1:mit->second++;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        int MAX=INT_MIN;
        vector<int>ret;
        for(map<int, int>::iterator mit=mmap.begin(); mit!=mmap.end(); mit++){
            MAX=mit->second>MAX?(ret.clear(), mit->second):MAX;
            if(mit->second==MAX)ret.push_back(mit->first);
        }
        return ret;   
    }
};
