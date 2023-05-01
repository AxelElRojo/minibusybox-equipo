CROSS_COMPILE =
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror
LIB_NAME = rm
TARGET = lib$(LIB_NAME).so
LIBS = -l$(LIB_NAME)

.PHONY: all install clean
all: $(TARGET)

$(TARGET): rm.c librm.h
	$(CC) $(CFLAGS) -c -fpic $< -o rm.o
	$(CC) -shared -o $@ rm.o
install: $(TARGET)
	scp $< debian@192.168.7.2:~/
	scp lib$(LIB_NAME).h debian@192.168.7.2:~/
clean:
	rm *.o *.so