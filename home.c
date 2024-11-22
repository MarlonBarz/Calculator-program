#include <stdio.h> //Direttiva
#include "generics.h"
#include "menu.h"

void stampaBenvenuto(){ //DICHIARAZIONE DI FUNZIONE = PROTOTIPO + CORPO

    printf("Ma anche no!\n"); //CORPO

};

int main(){
    int choose = 0;
    int exit = 0;
    int op1;
    int op2;
    
    while(!exit){
        printf("%s\n", showMenu());
        scanf("%d", &choose);
        
        
    }

    return 0;
}