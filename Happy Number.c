bool isHappy(int n) {
    int visitados[1000];
    int accont = 0;
    int soma = 0;
    int numero;
    while (accont < 1000) {
        for (int i = 0; i < accont; i++) {
            if (visitados[i] == n) {
                return false;
            }
        }
        visitados[accont] = n; // Armazene o valor original de n
        accont++;
        while (n > 0) {
            numero = n % 10;
            soma += (numero * numero);
            n /= 10;
        }
        if (soma == 1) {
            return true;
        }
        n = soma;
        soma = 0;
    }
    return false;
}
