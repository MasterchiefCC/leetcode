#include "mod.h"

struct TreeNode {
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
private:
    void comp(int&c_max, int&index, int p_max, int p_index){
        if(p_max>c_max){
            c_max=p_max;
            index=p_index;
        }
    }
    void Helper(vector<int>& nums, int i, int max, TreeNode*root){
        int m_max=-100, index=-1;
        for(int a=i-1; a>=0&&nums[a]<max; a--)comp(m_max, index, nums[a], a);
        if(i>0&&index!=-1){
            root->left=new TreeNode(m_max);
            Helper(nums, index, m_max, root->left);
        }
        m_max=-100;index=-1;
        int len =nums.size();
        for(int a=i+1; a<len&&nums[a]<max; a++)comp(m_max, index, nums[a], a);
        if(i<=len-1&&index!=-1){
            root->right=new TreeNode(m_max);
            Helper(nums, index, m_max, root->right);
        }
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int m_max=0, index=-1;
        for(int a=0;a <nums.size(); a++){
            comp(m_max, index, nums[a], a);
        }
        TreeNode*root = new TreeNode(m_max);
        Helper(nums, index, m_max, root);
        return root;
    }
};