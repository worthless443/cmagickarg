OBJ=vargs.o
LIB=libvargs.a
MAIN=main
FLAGS=-I./ -O3  -ggdb

all: $(OBJ) $(LIB) $(MAIN)
$(OBJ): %.o : %.c
	$(CC) -c ${FLAGS} $^ -o $@
$(LIB): $(OBJ)
	ar rcs $@ $^
$(MAIN): % : %.c
	$(CC) $^ $(LIB) ${FLAGS} -o $@
	
clean:
	rm -rf *.o *.a main
