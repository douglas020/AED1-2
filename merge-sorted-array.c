#include <stdio.h>
#include <stdlib.h>


int crescente (const void *a,const void * b){
    if (*(int *) a == * (int *) b)
        return 0;

    else
        if (*(int *)a < *(int *) b)
            return -1;
        else
        return 1;

}


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    
    int j=0;

    for (int i=m;i<nums1Size;i++){
        nums1[i] = nums2[j];
        j++;
    }

    qsort(nums1,nums1Size,sizeof(int),crescente);

}