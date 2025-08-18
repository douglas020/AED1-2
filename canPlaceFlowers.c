#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (n <0)
    return false;

    if (n > flowerbedSize)
    return false;

    if (n == flowerbedSize)
    return true;

    if (n == 0){
        return true;
    }

    if (flowerbed[n-1] == 1 &&  flowerbed[ +1] == 0)
    return true;

    if (flowerbed[n-1] == 0 &&  flowerbed[ +1] == 1)
    return true;




    return false;

}