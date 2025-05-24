bool isSameAfterReversals(int num) {
    int size=0,flag =0;
    int i=0;

    while (num > 0){

        int algarismo = num % 10;

        if (flag == 0 && algarismo == 0){
            return false;

        }else if(flag == 0 && algarismo != 0){
            return true;
        }
    }
}