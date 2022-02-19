#compiler name
cc := C:\MinGW\bin\gcc

#remove command
RM := rm -rf

#source files
SOURCES :=main.c keys.c protocol.c

#object files
OBJS :=$(SOURCES:.c=.o)

#main target
main: $(OBJS)
    $(CC) $^ -o $@

%.o: %.c
    $(CC) -c $< -o $@
 

.PHONY: clean
clean:
    $(RM) *.o main