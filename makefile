CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET2 = my_Knapsack
SRC = my_Knapsack.c
TARGET = my_graph
LIBRARY = my_mat

all: $(TARGET) $(TARGET2)

$(TARGET): $(TARGET).c $(LIBRARY).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(LIBRARY).o

$(TARGET2): $(SRC) 
	$(CC) -Wall  -o $(TARGET2) $(SRC)

$(LIBRARY).o: $(LIBRARY).c $(LIBRARY).h
	$(CC) $(CFLAGS) -c $(LIBRARY).c

clean:
	rm -f $(TARGET) $(LIBRARY).o $(TARGET2) $(TARGET2).o  

.PHONY: all clean
