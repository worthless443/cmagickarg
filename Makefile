CC=gcc
OBJ=vargs.o sort.o
LIB=libvargs.a
MAIN=main
FLAGS=-I./ -O3  -ggdb -Wall 
SRC_DIR=examples

all: $(OBJ) $(LIB) $(MAIN)
$(OBJ): %.o : %.c
	$(CC) -c ${FLAGS} $^ -o $@
$(LIB): $(OBJ)
	ar rcs $@ $^
$(MAIN): % : ${SRC_DIR}/%.c
	$(CC) $^ $(LIB) ${FLAGS} -o $@
	
clean:
	rm -rf ${OBJ} ${LIB} ${MAIN}
