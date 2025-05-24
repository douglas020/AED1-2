int findGCD(int* nums, int numsSize) {
    int menor,maior,flag = 0,flag1 = 0,mdc;

    for (int i=0;i<numsSize;i++){

        if (flag == 0){

            menor = nums[0];
            maior = nums[0];

            flag = 1;

        }

        if (nums[i] < menor ){
            menor = nums[i];
        }

        if (maior < nums[i]){
            maior = nums[i];
        }

    }

    for (int i=1;i <= maior;i++){

        if (maior % i == 0 && menor % i == 0){

          mdc = i;
            
        }
    }

   return mdc;

}