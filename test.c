#include<dirent.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

#include "config.h"

int global_i;
int eval_arguments(char *raw_arg, int *output) {
	int is_whole;
	char *arg = raw_arg  + 1;
	if(*raw_arg != '-') return 2;
	global_i = 1;
	if((is_whole = strlen(raw_arg + 1) > 1)) {
		for(int i=0;i<strlen(arg);++i) {
			++global_i;
			for(int j=0;j<strlen(_SUP_STRING);++j) {
				if(arg[i] == _SUP_STRING[j]) {
					output[j] = 1;
				}
			}
			for(int j=1;j<strlen(_SUP_STRING_BODY);++j) {
				if(arg[i] == _SUP_STRING_BODY[j]) {
					output[OP_BAR + j] = 1;
					return 1;
				}
			}
		}
	}

	else {
		for(int j=0;j<strlen(_SUP_STRING);++j) {
			if(*arg == _SUP_STRING[j]) {
				output[j] = 1;
			}
		}
		for(int j=1;j<strlen(_SUP_STRING_BODY);++j) {
			if(*arg == _SUP_STRING_BODY[j]) {
				output[OP_BAR + j] = 1;
				return 1;
			}
		}
	}
	return 0;
}


void eval_arg_body_2(int *options,char **output, char **arg, int *i) {
	int j = -1;
	char *_arg = arg[*i] + global_i;
	if(strlen(_arg) <= 0) _arg = arg[++*i];

	int _options[10] = {0};
	for(int _i = 0; _i < 14; ++_i)  {
		if(options[_i])  {
			_options[++j] = _i; 
		}
	}


	for(int _i = 0;_i < j;++_i) {
		int op_opt = _options[j];
		if(options[op_opt] && !arr[op_opt]) {
			if(strlen(_arg) > 1)  {
				for(int j=0;j<strlen(_arg);++j) {
					output[op_opt][j] = _arg[j];
				}
			}
			else  {
				output[op_opt] = arg[++*i];
			}
			arr[op_opt]+=1;
		}
	}

}


void eval_arg_body(int *options,char **output, char **arg, int *i) {
	char *_arg = arg[*i] + global_i;
	if(options[OP_COMMAND] && !PR_COMMAND) {
		if(strlen(_arg) > 1)  {
			for(int j=0;j<strlen(_arg);++j) {
				output[OP_COMMAND][j] = _arg[j];
			}
		}
		else 
			output[OP_COMMAND] = arg[++*i];
		++PR_COMMAND;
	}
	if(options[OP_ADD] && !PR_ADD) {
		if(strlen(_arg) > 1)  {
			for(int j=0;j<strlen(_arg);++j) {
				output[OP_ADD][j] =  _arg[j];
			}
		}
		else {
			output[OP_ADD] = arg[++*i];
		}
		++PR_ADD;
	}
	
}

char **get_op_strings(int size) {
	char **op_strings = malloc(sizeof(char*) * size);
	for(int i=0;i<10;++i)
		op_strings[i] = malloc(sizeof(char) * size);
	return op_strings;
}


void setup(int *ops, char **op_strings, int argc,char **argv) {
	for(int i=1,j = OP_BAR + 1;i<argc;++i,++j)  
		if(eval_arguments(argv[i], ops)) 
			eval_arg_body_2(ops,op_strings,argv,&i);
}

int main(int argc, char **argv) {
	memset(arr,'\0',10);
	int op = 0;
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
	return 1;
	
	return 1;
}
