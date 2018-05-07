#include "treemod.h"

class Solution {
    pair<int, int> helper( TreeNode*root){
        if(root==NULL)return make_pair(0, 0);

        pair<int, int> left=helper(root->left);
        pair<int, int>right=helper(root->right);

        pair<int, int>ret=make_pair(0, 0);
        ret.first=root->val+left.second+right.second;
        ret.second=max(left.first, left.second)+max(right.first,right.second);

        return ret;
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> ret=helper(root);
        return max(ret.first, ret.second);
    }
};

#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
void fib(int n){
    if(n==0||n==1){
        printf("%d ", n);
        return n;
    }
    else printf("%d", fib(n-1)+fib(n-2));
}
int value=5;
int main(int argc, char**argv){
    if(argc!=2||atoi(argv[1])<=0)return 0;
    
    pid_t pid;
    pid=fork();
    
    if(pid==0){/* child process*/
        fib(atoi(argv[1]));
    }
    else if(pid>0){/*parent process*/
        wait(NULL);
        exit(0);
    }
    exit(0);
}