char* intToRoman(int num) {
    char* roman = malloc(50 * sizeof(char)); // Aloca memória dinamicamente
    int index = 0;

    while (num > 0) {
        if (num >= 1000) {
            roman[index++] = 'M';
            num -= 1000;
        } else if (num >= 900) {
            roman[index++] = 'C';
            roman[index++] = 'M';
            num -= 900;
        } else if (num >= 500) {
            roman[index++] = 'D';
            num -= 500;
        } else if (num >= 400) {
            roman[index++] = 'C';
            roman[index++] = 'D';
            num -= 400;
        } else if (num >= 100) {
            roman[index++] = 'C';
            num -= 100;
        } else if (num >= 90) {
            roman[index++] = 'X';
            roman[index++] = 'C';
            num -= 90;
        } else if (num >= 50) {
            roman[index++] = 'L';
            num -= 50;
        } else if (num >= 40) {
            roman[index++] = 'X';
            roman[index++] = 'L';
            num -= 40;
        } else if (num >= 10) {
            roman[index++] = 'X';
            num -= 10;
        } else if (num >= 9) {
            roman[index++] = 'I';
            roman[index++] = 'X';
            num -= 9;
        } else if (num >= 5) {
            roman[index++] = 'V';
            num -= 5;
        } else if (num >= 4) {
            roman[index++] = 'I';
            roman[index++] = 'V';
            num -= 4;
        } else if (num >= 1) {
            roman[index++] = 'I';
            num -= 1;
        }
    }
    
    roman[index] = '\0'; 
    return roman;
}