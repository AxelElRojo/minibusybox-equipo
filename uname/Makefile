CROSS_COMPILE =
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror
LIB_NAME = uname
TARGET = lib$(LIB_NAME).so
LIBS = -l$(LIB_NAME)

.PHONY: all install clean
all: $(TARGET)

$(TARGET): $(LIB_NAME).c lib$(LIB_NAME).h
	$(CC) $(CFLAGS) -c -fpic $< -o $(LIB_NAME).o
	$(CC) -shared -o $@ $(LIB_NAME).o
install: $(TARGET)
	scp $< debian@192.168.7.2:~/
	scp lib$(LIB_NAME).h debian@192.168.7.2:~/
clean:
	rm *.o *.so