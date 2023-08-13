#define _BLOCKED_CHARS "|() *&^%$#@!~"
#define _SUP_STRING "bdev"
#define _SUP_STRING_BODY "~acnfglkxy"
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
	OP_K,
	OP_X,
	OP_Y
};

#define MAX_ARGN 20
