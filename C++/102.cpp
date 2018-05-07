#include"treemod.h"
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
    vector<vector<int>>ret;
    void helper(queue <TreeNode*>&m_queue, int size){
        if(size==0)return;
        vector<int>m_tail(size, 0);
        int index=0, nxt_level=0;
        while(!m_queue.empty()&&size--){
            TreeNode*temp=m_queue.front();
            m_queue.pop();
            if(temp->left!=NULL){
                m_queue.push(temp->left);
                ++nxt_level;
            }
            if(temp->right!=NULL){
                m_queue.push(temp->right);
                ++nxt_level;
            }
            m_tail[index++]=temp->val;
        }
        ret.push_back(m_tail);
        helper(m_queue, nxt_level);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {    
        ret.clear();
        queue<TreeNode*>buffer;
        buffer.push(root);
        int size=root==NULL?0:1;
        helper(buffer, size);
        return ret;
    }
};