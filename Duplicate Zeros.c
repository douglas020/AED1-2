#include <stdio.h>


int main (){
int size=8;
int arr[8] = {1,0,2,3,0,4,5,0};
int aux[8];


for (int i=0;i<size;i++){
    aux[i] = arr[i];
}

for (int i=0 ;i<size;i++){
    if (arr[i] == 0){
        int index = i+1 ;
       
        
        for (int j=i;j<size;j++){
            arr[j] = aux[index];
           index +=1;

        }
        i += 1;
    }
}

for (int i=0;i<size;i++){
    printf ("Array %d: %d \n",i,arr[i]);
}

}