#include <stdio.h>
#include <stdlib.h>

int main  (){
int nums[] = {1,2,3,1,2,3};
int numsSize = 6;
int k = 2;


    for (int i=0;i<numsSize;i++){
        int aux = k;

        for (int j=i+1;j<numsSize;j++){
            
            if (nums[i] == nums[j]){
                printf ("passou \n");
            }

           --k;
           if (aux == 0)
           break;
        }     
    }

}
// No terminei