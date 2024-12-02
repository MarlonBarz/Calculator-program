#include <stdio.h> //Direttiva
#include "generics.h"
#include "menu.h"
#include "operations.h"
void stampaBenvenuto(){ //DICHIARAZIONE DI FUNZIONE = PROTOTIPO + CORPO

    printf("Funzione senza output!\n"); //CORPO

};

int main(){
    int choose = 0;
    int exit = 0;
    float valueConst = 0.0;
    int valueIns = 0;
    
    while(!exit){
        printf("%s\n", showMenu());
        scanf("%d", &choose);
        
        if(choose == 5){
            exit = 1;
            printf("\n\nArrivederci zebi!");
            break;
        }
        
        printf("Inserci il valore per continuare con l'operazione scelta:\n");
        scanf("%d", &valueIns);

        switch (choose){
            case 1:
                valueConst = (double) sum(valueIns,valueConst); 
                break;
            
            case 2:
                valueConst = (double) sub(valueIns,valueConst);
                break;
            
            case 3:
                valueConst = (double) mult(valueIns, valueConst);
                break;

            case 4:
                valueConst = (double) res(valueIns, valueConst);
                break;

            default:
                printf("Commando non riconosciuto, riprova.\n\n");
                break;
        }
        
        printf("Risultato: %.2f\n\n", valueConst);
    }

    return 0;
}