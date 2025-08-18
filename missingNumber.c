int missingNumber(int* nums, int numsSize) {
    int flag;
    int search=0;

    for (int i=0;i<numsSize;i++){
        flag=0;

        for (int j=0;j<numsSize;j++){
            if (search == nums[j]){
                flag=1;
                search++;
                continue;
            }
        }

        if (flag == 0){

            return search;        
        }
    }
    return numsSize;
}