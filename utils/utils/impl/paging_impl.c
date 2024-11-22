#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "generics.h"

// Dynamic Paging
char * configPag(int size, char *content){
    printf("\n\n******************************* START configPag - paging_impl *******************************\n\n");

    //Check before start
    if(size < 50)
        size = 50;

    //Variables for Page
    int height = (int) ceil((double) length(content) / ((double) size / 2)) + 4; // 4 because i need 2 rows dedicated for first and last row, another 2 rows with no text
    int lastPosCol = height - 1;
    int lastPosRow = size + 1;

    //Variables for Content of Page
    int indexContent = 0;
    int startContent = (int) floor((double) size / 4);
    int sizeContent = (int) ceil((double) size / 2);
    int lastCharRow = size - 1;

    // Allocazione della memoria per il risultato finale
    char *result = (char *) malloc(sizeof(char) * (height * lastPosRow + 1)); // +1 per il terminatore
    if (!result) {
        printf("Errore: allocazione memoria fallita per la variabile RESULT\n");
        return NULL;
    }
    result[0] = '\0'; // Init result

    // The FUNCTION is divided in 4 PARTS
    for(int i = 0; i < height; i++){
        // Allocazione della memoria per la riga in uso
        char *row = (char *)malloc(sizeof(char) * (lastPosRow + 1)); // +1 per il terminatore '\0'
        if (!row) {
            printf("Errore: allocazione memoria fallita per la variabile ROW\n");
            free(result);
            return NULL;
        }
        row[0] = '\0'; // Init row

        // PART 1: This part set the first row
        if(i == 0){
            printf("START configPag {PART 1} - paging_impl\n");
            for(int j = 0; j < lastPosRow + 1; j++){

                if(j == 0)
                    *(row + j) = (char)218;
                
                if(j == size - 1)
                    *(row + j) = (char)191;

                if(j > 0 && j <= lastCharRow - 1)
                    *(row + j) = (char)196;
            }
            printf("END configPag {PART 1} - paging_impl\n");
        }

        // PART 2: This part set the last row
        if(i == lastPosCol){
            printf("START configPag {PART 2} - paging_impl\n");
            for(int j = 0; j < lastPosRow + 1; j++){
                if(j == 0)
                    *(row + j) = (char)192;
                
                if(j == size - 1)
                    *(row + j) = (char)217;
                
                if(j > 0 && j <= lastCharRow - 1)
                    *(row + j) = (char)196;
            }
            printf("END configPag {PART 2} - paging_impl\n");
        }

        //PART 3: I want couple rows without text. Visual utility for user
        if(i == 1 || i == lastPosCol - 1){
            printf("START configPag {PART 3} - paging_impl\n");
            for(int j = 0; j < lastPosRow + 1; j++){
                if(j == 0 || j == size - 1)
                    *(row + j) = (char)179;

                if(j > 0 && j <= lastCharRow - 1)
                    *(row + j) = (char)32;
            }
            printf("END configPag {PART 3} - paging_impl\n");
        }   

        // PART 4: This part set the content of my Pag. This is the most complicated of 4
        if(i > 1 && i < lastPosCol - 1){
            printf("START configPag {PART 4} - paging_impl\n");
            for(int j = 0; j < lastPosRow + 1; j++){

                if(j == 0 || j == size - 1)
                    *(row + j) = (char)179;

                if(j > 0 && j <= lastCharRow - 1){
                    if(j < startContent || j >= (startContent + sizeContent) && j <= lastCharRow - 1)
                        *(row + j) = (char)32;

                    if(j >= startContent && j < (startContent + sizeContent)){
                        if (indexContent < length(content)) {
                            *(row + j) = *(content + indexContent);
                            indexContent++;
                        } else {
                            *(row + j) = (char)32; // Aggiungi spazio se il contenuto è finito, altrimenti altri problemi
                        }
                    }
                }
            }
            printf("END configPag {PART 4} - paging_impl\n");
        }

        *(row + size) = '\n';   // Add a newline character
        *(row + lastPosRow) = '\0'; // Add a null terminator after the newline
        
        //Add the row to result, IMPORTANT
        int m = 0, n = 0;

        // Find the end of the first string
        while (result[m] != '\0') {
            m++;
        }

        // Append the second string
        while (row[n] != '\0') {
            result[m] = row[n];
            m++;
            n++;
        }

        //IMPORTANT: RESULT MUST END WITH THIS ANNOTATION, OTHERWISE WE WILL SEE EMOJIS (-_-)
        result[m] = '\0';

        //Log row to check result
        printf("Vediamo RESULT:\n");
        printf("%s\n", result);
        free(row);
    }
    printf("\n\n******************************* END configPag - paging_impl *******************************\n\n");
    return result;
};
