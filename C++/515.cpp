#include "treemod.h"
 class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>ret;
        queue<TreeNode*> Node;
        if(root==NULL)return ret;
        int level=0;
        int node_on_next=1;
        Node.push(root);
        while(!Node.empty()){
            int max_val=INT_MIN;
            int next_level=0;
            int cnt=node_on_next;
            node_on_next=0;
            while(cnt--){
                TreeNode*temp=Node.front();
                max_val=max(temp->val, max_val);
                if(temp->left!=NULL){
                    node_on_next++;
                    Node.push(temp->left);
                }
                if(temp->right!=NULL){
                    node_on_next++;
                    Node.push(temp->right);
                }
                Node.pop();
            }
            ret.push_back(max_val);
        }
        return ret;
    }
};