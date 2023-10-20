CC=g++
STD=-std=c++11
FLAG=-Wall -Werror
TARGET=EMIS
OBJ=main.o manager.o manager_view_impl.o manager_ctrl_impl.o manager_mode_impl.o employee.o department.o service_view_impl.o service_ctrl_impl.o service_mode_impl.o emis.o tools.o

.PHONY:all
all:$(OBJ)
	$(CC) $(OBJ) -o $(TARGET) && ./$(TARGET)
	
%.o:%.cpp
	$(CC) -c $(FLAG) $(STD) $< -o $@
	
.PHONY:clean
clean:
	rm -rf $(OBJ) $(TARGET)
	rm -rf *.h.gch *~
