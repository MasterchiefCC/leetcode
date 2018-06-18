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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        queue<pair<TreeNode*, int>>m_queue;
        m_queue.push({root, 1});
        int ret=0;
        while(!m_queue.empty()){
            int len=m_queue.size(), left=m_queue.front().second, right=left;
            for(int i=0; i<len; ++i){
                TreeNode*temp=m_queue.front().first;
                right=m_queue.front().second;
                m_queue.pop();
                if(temp->left!=NULL)m_queue.push({temp->left, right*2});
                if(temp->right!=NULL)m_queue.push({temp->right, right*2+1});
            }
            ret=max(ret, right-left+1);
        }
        return ret;
    }
};