TARGET = prof/analysis.out
APP = prof/app
OUT = gmon.out
SRC = polymental.c opt.c
OBJ = $(SRC:.c=.o)
CC = cc
C_FLAG = -Og -pg

$(TARGET): $(APP) $(OUT)
	gprof $(APP) $(OUT) > $(TARGET)

$(APP): $(OBJ)
	$(CC) $(C_FLAG) $^ -o $@

$(OBJ): %.o: %.c
	$(CC) $(C_FLAG) -c $< -o $@

$(OUT): $(APP)
	./$(APP)

.PHONY: clean
clean:
	rm -f $(TARGET) $(APP) $(OUT) $(OBJ)