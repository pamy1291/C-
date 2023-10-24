CC=g++
STD=-std=c++11
FLAG=-Wall -Werror
BIN=Hotel
OBJ=main.o run.o guest.o room.o hotel.o tools.o
INC=tools.h guest.h hotel.h room.h run.h

all:$(OBJ)
	$(CC) $(OBJ) -o $(BIN) && ./Hotel
	
%.o:%.cpp $(INC)
	$(CC) -c $(STD) $(FLAG) $< -o $@

.PHONY:clean	
clean:
	rm -rf $(BIN)
	rm -rf *.h.gch *.o

