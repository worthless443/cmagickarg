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

# Future 
As of commit c78811bfc8106dc3ee38982589902c683cefc000, postion independent argument passing convention has not been resolved, and therefore has not been posible at all. It does however support varidaic arguments which follos the similiar convention of right-to-left. 

In the future, I emvision to port the entire mechanism as a macro (CPP).

# Limitations

This parsing utility and library has number of problems associated with incompatiblity, misbehaviour and lastly a position-dependent argument passing mechanism. One thing to specifically note is that the named enum field and the macro strintg must align with each other, that means the entries for command line options must be layed out in order of either the named enum or the string which dictates how to interpret the position depenedent arugments.

# Contributions 

Concered with Limitations, feel free to contribute code in order to make the program and library interface better. 
