#include "treemod.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        if(root==NULL)return ret;
        bool is_reverse=false;
        queue<TreeNode*>m_queue;
        m_queue.push(root);
        int cnt_nxt=1;
        while(!m_queue.empty()){
            vector<int>levl;
            int temp_cnt=0;
            
            for(int i=0; i<cnt_nxt; ++i){
                TreeNode*temp_Node=m_queue.front();
                m_queue.pop();
                levl.push_back(temp_Node->val);
                
                if(temp_Node->left!=NULL){
                    m_queue.push(temp_Node->left);
                    ++temp_cnt;
                }
                if(temp_Node->right!=NULL){
                    m_queue.push(temp_Node->right);
                    ++temp_cnt;
                }
            }
            
            if(is_reverse)std::reverse(levl.begin(), levl.end());
            ret.push_back(levl);
            is_reverse=!is_reverse;
            cnt_nxt=temp_cnt;
        }
        
        return ret;
    }
};