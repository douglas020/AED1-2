#include <stdio.h>

int main (){
int digitis [] = {4,3,2,1};
int n=1,a=0;
int v[4];
int index=3;
for (int i=4-1;i>=0;i--){
    
    a += digitis[i] * n;
    n = n *  10;
}
a +=1;

while (a > 0){
    int algarismo = a % 10;

    v [index] = algarismo;
    --index;
    a /= 10;
}
 
for (int i=0;i<4;i++){
printf ("%d \n",v[i]);
}


}