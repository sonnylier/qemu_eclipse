#define SYSCALLTEST 0

#define GADGET 0

#define SAFE_INSTRUCTIONS 1
#define RJMP 1
#define MJMP 1

/*********     stack   switch   ********/
#define SHADOW_STACK 0
#define TRA_SHADOW_STACK 0  /*First setting SHADOW_STACK = 1 then setting TRA = 1*/
#define NO2OPTIMIZE 0  /*First setting SHADOW_STACK = 1 then setting  = 1*/

#define NO_OPTIMIZE_NOSTACK 0  /*No stack, but removing one optimization*/
#define NO2OPTIMIZE_NOSTACK 0  /*No stack, but removing tow optimization*/
/***************************************/

#define PREVENT_UNINTEND 0

#define TBN 5


