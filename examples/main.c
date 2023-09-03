#include "vargs.h"
#include "config.h"
#include<stdio.h>
#include<string.h>

extern int PR_COMMAND,PR_ADD;
extern int arr[15];
extern int idx;
extern int ops[15];

int main(int argc, char **argv) {
	memset(arr,'\0',10);
	char **op_strings =  get_op_strings(100);
	
	setup(ops,op_strings, argc,argv);
	if(ops[OP_COMMAND])
		printf("c = %s\n",op_strings[OP_COMMAND]);
	if(ops[OP_NAME])
		printf("n = %s\n",op_strings[OP_NAME]);
	if(ops[OP_FIT])
		printf("f = %s\n",op_strings[OP_FIT]);
	if(ops[OP_GAY])
		printf("g = %s\n",op_strings[OP_GAY]);
	if(ops[OP_EDIT])
		printf("editing is enabled\n");
	if(ops[OP_L])
		printf("l = %s\n", op_strings[OP_L]);
	if(ops[OP_K])
		printf("k = %s\n", op_strings[OP_K]);
	if(ops[OP_ADD])
		printf("a = %s\n", op_strings[OP_ADD]);
	if(ops[OP_X])
		printf("x = %s\n", op_strings[OP_X]);
	if(ops[OP_Y])
		printf("y = %s\n", op_strings[OP_Y]);
	return 1;
	
	return 1;
}

