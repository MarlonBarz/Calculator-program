#include <stdio.h>
#include <stdlib.h>
#include "paging.h"
#include "generics.h"

char* showMenu(){
    char *menuText = "Benvenuto! Indicami quale operazione vorresti effettuare: 1)Somma 2)Sottrazione 3)Moltiplicazione 4)Modulo 5)Esci";
    //char *noText = "";
    return configPag(0, menuText);
    free(menuText);
    //free(noText);
}
