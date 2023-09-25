CC = gcc -Wall -Werror -Wextra -std=gnu11
TARGET = ShowFunc

PREF_SRC = ../src/
PREF_OBJ = ../obj/
PREF_TARGET = ../build/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(PREF_TARGET)$(TARGET) -lm

$(PREF_OBJ)%.o: $(PREF_SRC)%.c
	$(CC) -c $< -o $@ -lm

clean:
	rm $(PREF_TARGET)$(TARGET) $(PREF_OBJ)*.o $(PREF_TARGET)*.out

clang:
	clang-format -i *.c *.h

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem $(PREF_SRC)$(SRC)