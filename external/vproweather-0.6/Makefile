CC = gcc
CFLAGS = -O2 -Wall -fpack-struct -I/usr/include -I./include 

TARGET = vproweather
all:	$(TARGET)

$(TARGET): main.o dhandler.o
	$(CC) main.o dhandler.o -o $(TARGET)

main.o: main.c include/main.h include/dhandler.h
	$(CC) $(CFLAGS) -c main.c

dhandler.o: dhandler.c include/dhandler.h include/names.h
	$(CC) $(CFLAGS) -c dhandler.c

clean:
	rm -f $(TARGET) *.o

