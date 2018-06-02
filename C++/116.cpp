#include "mod.h"

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)return;
        vector<TreeLinkNode*>buffer;
        buffer.push_back(root);
        buffer.push_back(NULL);
        while(buffer.size()>1){
            vector<TreeLinkNode*>t_buffer;
            for(int i=0; i<buffer.size()-1; ++i){
                if(buffer[i]->left!=NULL)t_buffer.push_back(buffer[i]->left);
                
                if(buffer[i]->right!=NULL)t_buffer.push_back(buffer[i]->right);
                
                buffer[i]->next=buffer[i+1];
            }
            t_buffer.push_back(NULL);
            buffer=t_buffer;
        }
    }
};