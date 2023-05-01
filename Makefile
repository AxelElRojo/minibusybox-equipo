CROSS_COMPILE =
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror
TARGET = minibusybox
LIB_MKDIR = mkdir
LIB_UNAME = uname
LIB_RM = rm
LIBS = -lmkdir -luname -lrm
MAIN = minibusybox.c

.PHONY: all install clean

all: $(TARGET)

$(TARGET): main.o lib$(LIB_MKDIR).so lib$(LIB_UNAME).so lib$(LIB_RM).so
	$(CC) $(CFLAGS) $< $(LIBS) -L./$(LIB_MKDIR) -L./$(LIB_UNAME) -L./$(LIB_RM) -o $@
main.o: $(MAIN)
	$(CC) $(CFLAGS) -c $< -o $@
lib$(LIB_MKDIR).so:
	cd $(LIB_MKDIR) && make CROSS_COMPILE=$(CROSS_COMPILE)
lib$(LIB_UNAME).so: $(LIB_UNAME)/$(LIB_UNAME).c $(LIB_UNAME)/lib$(LIB_UNAME).h
	cd $(LIB_UNAME) && make CROSS_COMPILE=$(CROSS_COMPILE)
lib$(LIB_RM).so: $(LIB_RM)/$(LIB_RM).c $(LIB_RM)/lib$(LIB_RM).h
	cd $(LIB_RM) && make CROSS_COMPILE=$(CROSS_COMPILE)
install:
	scp $(TARGET) debian@192.168.7.2:~/
	cd mkdir && make install
	cd uname && make install
	cd rm && make install
clean:
	rm *.o $(TARGET)
	cd $(LIB_MKDIR) && make clean
	cd $(LIB_UNAME) && make clean
	cd $(LIB_RM) && make clean