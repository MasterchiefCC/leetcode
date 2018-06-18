#include "mod.h"

int* twoSum(int* nums, int numsSize, int target) {
    int ret1, ret2;
    for(int a=0; a<numsSize; a++){
        for(int b=a+1; b<numsSize; b++){
            if(*(nums+a)+*(nums+b)==target){
                ret1=a;
                ret2=b;
                break;
            }
        }
    }
    *nums=ret1;
    *(nums+1)=ret2;
    return nums;
}
