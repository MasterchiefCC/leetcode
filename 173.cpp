#include "treemod.h"

class BSTIterator {
    stack<TreeNode*>m_stack;
public:
    BSTIterator(TreeNode *temp) {
        while(temp!=NULL){
            m_stack.push(temp);
            temp=temp->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !m_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode*temp=m_stack.top();
        m_stack.pop();

        int ret=temp->val;

        if(temp->right){
            TreeNode*node=temp->right;
            while(node){
                m_stack.push(node);
                node=node->left;
            }
        }
        return ret;
    }
};