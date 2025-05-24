int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int soma=0;
    if (digits == NULL){
        return NULL;
    }

    if (digits[digitsSize - 1] == 9){
          int i = digitsSize - 1;
    
    while (i >= 0 && digits[i] == 9) {
        digits[i] = 0;
        i--;
    }
    
    if (i >= 0) {
        digits[i]++;
        *returnSize = digitsSize;
        
        int* result = (int*)malloc(digitsSize * sizeof(int));
        for (int j = 0; j < digitsSize; j++) {
            result[j] = digits[j];
        }
        return result;
    }
    
    *returnSize = digitsSize + 1;
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    
    result[0] = 1;
    for (int j = 1; j <= digitsSize; j++) {
        result[j] = 0;
    }
    
    return result;

    }else{
        *returnSize = digitsSize;
        int *p = malloc (digitsSize * sizeof(int));

        for (int i=0;i<digitsSize;i++){
            
            p[i] = digits[i];

        }

        p[digitsSize-1] += 1;

        return p;
    }
 


}