#define _BLOCKED_CHARS "|() *&^%$#@!~"
#define _SUP_STRING "bdev"
#define _SUP_STRING_BODY "~acnfglk"
#define _ARG_MAP(arg) (arg == 'e') ? OP_EDIT : (arg == '')
// change this enum according to required parameters for the program
enum OP {
	OP_B,
	OP_D,
	OP_EDIT,
	OP_ARG,
	OP_READ,
	OP_BAR, // mandatory field
	OP_ADD,
	OP_COMMAND,
	OP_NAME,
	OP_FIT,
	OP_GAY,
	OP_L,
	OP_K
};

int PR_COMMAND = 0, PR_ADD = 0;
int arr[10] = {0};
int idx = 0;
int ops[10] = {0};
