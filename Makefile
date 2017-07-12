CC=gcc
SRC_DIR=.

SRC_OBJECTS = 	$(SRC_DIR)/main.o \
		$(SRC_DIR)/Tabuleiro.o \

damas: $(SRC_OBJECTS)
	$(CC) -o damasED $(SRC_OBJECTS)
	# Compilado com sucesso!
	# Execute agora: ./damasED!
	@rm $(SRC_DIR)/*.o


clean:
	rm damasED
