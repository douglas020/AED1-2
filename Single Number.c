#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int flag;

    for (int i=0;i<numsSize;i++){
        flag=0;

        for (int j=0;j<numsSize;j++){
            if (nums[i] == nums[j] && i != j){
                flag = 1;
                continue;
            }
        }

        if (flag == 0 ){
            return nums[i];
        }
    }

    return nums[numsSize-1];
}