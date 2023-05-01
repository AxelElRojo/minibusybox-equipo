CROSS_COMPILE =
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror
TARGET = librm.so
LIBS = -lrm

.PHONY: all install clean
all: $(TARGET)

$(TARGET): rm.c librm.h
	$(CC) $(CFLAGS) -c -fpic $< -o rm.o
	$(CC) -shared -o $@ rm.o
install: $(TARGET)
	sudo cp $< /usr/lib
	sudo cp librm.h /usr/include
clean:
	rm *.o *.so