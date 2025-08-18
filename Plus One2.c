#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
int digitsSize =4;
int digits [] = {4,3,2,1};
int v[4] ;
int n=1,a=0;
int index;
int flag =0;
int *p;
 
for (int i=0;i<digitsSize;i++){
 if (digits[i] != 9 ){
    flag = 1;
    break;
 }
}

if (flag == 0){ 
 index = digitsSize -1 ;
  *p = (int *) malloc ((digitsSize + 1)* sizeof(int));
}

else{
    index = digitsSize;
  *p = (int *) malloc (digitsSize  * sizeof(int));
}


for (int i=0;i<digitsSize;i++){ // pega array e deixa em um numero inteiro {1,2,3} == 1230
    a += digits[i] * n;

    a *=  10;
}
a = a /10;
a += 1;
printf ("%d ",a);

for (int i=0;i<index;i++){
    int algarismo = a / pow(10, index-i-1);
    p[i] = algarismo;
}

//for (int i=0;i<digitsSize;i++)
//printf ("array %d: %d \n",i,v[i]);



}