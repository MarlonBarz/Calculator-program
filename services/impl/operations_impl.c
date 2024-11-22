#include <stdio.h>

int sum(int value, int optional){
    if(optional == 0){
        printf("Indicami il valore da sommare\n");
        return -111111;
    } else if(value == -111111){
        printf("Vuoi continuare a usare la somma?\n");
        return -111111;
    } else {
        return value + optional;
    }
}

int sub(int value, int optional){
    if(optional == 0){
        printf("Indicami il valore da sottrarre\n");
        return -222222;
    } else if(value == -222222){
        printf("Vuoi continuare a usare la sottrazione?\n");
        return -222222;
    } else {
        return value - optional;
    }
}

int mult(int value, int optional){
    if(optional == 0){
        printf("Indicami il valore da moltiplicare\n");
        return -333333;
    } else if(value == 0 && optional == 0){
        printf("Indeterminato\n");
        return -333333;
    } else if(value == -333333){
        printf("Vuoi continuare a usare il resto?\n");
        return -333333;
    } else {
        return value * optional;
    }
}

int res(int value, int restOf, int optional){
    if(optional == 0){
        printf("Indicami il valore da restare\n");
        return -444444;
    } else if(restOf == 0){
        printf("Impossibile\n");
        return -444444;
    } else if(value == -444444){
        printf("Vuoi continuare a usare il resto?\n");
        return -44444;
    } else {
        return value * optional;
    }
}
