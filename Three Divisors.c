bool isThree(int n) {
    int aux=1;

    for (int i=1;i<n;i++){

        if (n % i == 0){
            aux++;

            if (aux > 3){
                return false;
            }
        }
    }

    if (aux == 3){
        return true;
    }

    return false;
}