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
class Codec {
    void ser_handler(TreeNode*root, string &s){
        if(root==NULL)return;
        s.append(reinterpret_cast<const char*>(&root->val), sizeof(root->val));
        ser_handler(root->left, s);
        ser_handler(root->right, s);
    }

    TreeNode* des_handler(const string &ser, int cur_min, int cur_max, int &pos){
        if(pos>=ser.size())return NULL;
        int cur_val=*reinterpret_cast<const int*>(ser.data()+pos);
        if(cur_val<cur_min||cur_val>cur_max)return NULL;
        TreeNode*root=new TreeNode(cur_val);
        pos+=sizeof(cur_val);
        root->left=des_handler(ser, cur_min, cur_val, pos);
        root->right=des_handler(ser, cur_val, cur_max, pos);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        ser_handler(root, ret);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos=0;
        TreeNode*ret=des_handler(data, INT_MIN, INT_MAX, pos);
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));