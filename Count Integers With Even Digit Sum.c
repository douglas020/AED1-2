int countEven(int num) {
    int aux=0;

    for (int i=1;i<=num;i++){
        int soma = 0;

        if (i < 10 && i % 2 == 0){
            aux++;

        }else if ( i > 10  ) {
            int number = i;

            while (number > 0 ){

                int algarismo = number % 10;

                soma += algarismo;

                number /= 10;

                

            }

            if ( soma % 2 == 0){
                aux ++;
            }


        }

    }

    return aux;

}