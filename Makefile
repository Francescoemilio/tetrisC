CC = gcc

# Opzioni di compilazione
# -I seguito da un path indica dove trovare quel path.
CFLAGS = -Wall -g

# Cartelle
SRC_DIR = files # Cartella dei file .c
OBJ_DIR = obj # Cartella dei file .o

# Target principale
tetris:
	$(CC) $(CFLAGS) -o $@ files/blocco.c files/funzioni.c files/main.c files/elemento.c


# Regole di compilazione

# Pulizia dei file generati
# /Q = non chiedere conferma
clean:
	del /Q $(OBJ_DIR)\*.o 2>nul