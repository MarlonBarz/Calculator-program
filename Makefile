GCC = gcc # le variabili sono a propria discrezione, non c'è bisogno di usare nomi specifici
FOLDERS = -I./services -I./utils # RICORDATI di aggiornare questa variabile se aggiungi altre cartelle
SRC = $(shell find . -name "*.c") # wildcard prende dinamicamente tutti i file con estensione.c e soprattutto è riconosciuto dal comando MAKE
OUT_NAME = default_name # Il nome di default che prende OUT_NAME ma si può modificare con make OUT_NAME=cambioNome all
all: $(OUT_NAME) # QUELLO CHE C'E' A SINISTRA DEI DUE PUNTI E' L'OUTPUT, A DESTRA LE DIPENDENZE (input)
$(OUT_NAME): $(SRC)
	$(GCC) $(FOLDERS) $(SRC) -o $(OUT_NAME)
clean: 
	rm -f $(OUT_NAME)