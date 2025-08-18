#include <stdlib.h>
#include <stdbool.h>

int crescente (const void *a,const void * b){
    if (*(int *) a == * (int *) b)
        return 0;

    else
        if (*(int *)a < *(int *) b)
            return -1;
        else
        return 1;

}

bool containsDuplicate(int* nums, int numsSize) {
    
    qsort(nums,numsSize,sizeof(int),crescente);

    for (int i=0;i<numsSize-1;i++){
        if (nums[i] == nums[i + 1]){
            return true;
        }
    }
    return false;
}