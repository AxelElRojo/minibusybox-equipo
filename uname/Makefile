CROSS_COMPILE =
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror
TARGET = libuname.so
LIB_NAME = uname
LIBS = -luname

.PHONY: all install clean
all: $(TARGET)

$(TARGET): $(LIB_NAME).c lib$(LIB_NAME).h
	$(CC) $(CFLAGS) -c -fpic $< -o $(LIB_NAME).o
	$(CC) -shared -o $@ $(LIB_NAME).o
install: $(TARGET)
	sudo cp $< /usr/lib
	sudo cp lib$(LIB_NAME).h /usr/include
clean:
	rm *.o *.so