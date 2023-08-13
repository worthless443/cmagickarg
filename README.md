# C Arg Parse 

CArgParse is convinient way to add or remove functionality from your program which requires fields from multiple options. Providing a Makefile which emits some object files and an executale of whichever program you are trying to use it with.  

# Examples

By making changes to `config.h` can be used for making changes for the list of arugments and their subsequent fields. 

### Using the code provided with this repo

Add or remove individual chars from the macro `_SUB_STRING` and `_SUB_STRING_BODY` where one must not start with and the opposite 
respectively. 

For example,
```C
-- #define _SUB_STRING "~abcdefg"
++ #define _SUB_STRING "~abcdefgy"

```
we added the `y` option. Now the variable `ops[OP_Y]` is set true and `op_strings[OP_Y]` contains the field or body that has been passed to `-y` by `-yyes` or `-y yes`.

```C
if(ops[OP_Y]) {
    printf("y = %s\n",op_strings[OP_Y])
    ...
}
```
Now compile it all 
```
$ CC=gcc CXX=g++ make 
./main -vy comm -z test -ggay
```

## Disclaimer
This is not ready to be used, not yet as of now. 
