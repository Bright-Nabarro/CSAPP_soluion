TARGET = app
OBJ = transpose.o main.o
C_DEFAULT = cc -O1 -Wall

$(TARGET): $(OBJ)
	$(C_DEFAULT) $^ -o $@

$(OBJ): %.o: %.c
	$(C_DEFAULT) -c $< -o $@

.PHONY:
	clean

clean:
	rm -f $(TARGET) $(OBJ)