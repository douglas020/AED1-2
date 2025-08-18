#include <stdio.h>
#include <stdlib.h>
int removeElement(int* nums, int numsSize, int val) {
int k=0;
 int* aux = (int*) malloc(numsSize * sizeof(int));

for (int i=0;i< numsSize ;i++){
    if (val != nums[i]){
        aux[k] = nums[i];
        k++;
    }
}
for (int i=0;i<k;i++){
    nums[i] = aux[i];
}

free(aux);

return k;
}

int main (){
   printf ("Calvo"); 
}