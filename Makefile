CC := gcc
CFLAGS = -Wall -Wextra -O2

OBJECT_DIR = obj
$(shell mkdir -p $(OBJECT_DIR))

all: temperature.exe football.exe

football.exe: football_main.o football.o
	$(CC) $(CFLAGS) $(OBJECT_DIR)/football_main.o $(OBJECT_DIR)/football.o -o football.exe

temperature.exe: temperature_main.o temperature.o
	$(CC) $(CFLAGS) $(OBJECT_DIR)/temperature_main.o $(OBJECT_DIR)/temperature.o -o temperature.exe

football.o: football.c football.h
	$(CC) $(CFLAGS) -c football.c -o $(OBJECT_DIR)/football.o

football_main.o: football_main.c football.h
	$(CC) $(CFLAGS) -c football_main.c -o $(OBJECT_DIR)/football_main.o

temperature.o: temperature.c temperature.h
	$(CC) $(CFLAGS) -c temperature.c -o $(OBJECT_DIR)/temperature.o

temperature_main.o: temperature_main.c temperature.h
	$(CC) $(CFLAGS) -c temperature_main.c -o $(OBJECT_DIR)/temperature_main.o

clean:
	rm -rf football.exe temperature.exe $(OBJECT_DIR)
