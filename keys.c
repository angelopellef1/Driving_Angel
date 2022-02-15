#include "keys.h"


/*Ex. Alt+M and key down twice*/
struct Key_Action Pos_second_row[1] = {
    {COMBO,     1,  K_ALT,      KEY_M,  NULL},
    {SINGLE,    2,  KEY_DOWN,   NULL,   NULL}
};


/*Ex. UNTESTED damage reparir removal
* open menu, scroll down 7 times, left arrow
*/
struct Key_Action Pos_DoNotRepair[1] = {
    {COMBO,     1,  K_ALT,      KEY_M,  NULL},
    {SINGLE,    7,  KEY_DOWN,   NULL,   NULL},
    {SINGLE,    1,  KEY_LEFT,   NULL,   NULL},
};

