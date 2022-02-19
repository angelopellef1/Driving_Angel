#include "keys.h"
#include <windows.h>

//https://docs.microsoft.com/it-it/windows/win32/inputdev/virtual-key-codes



struct Key_Action Pos_second_row[3] = {
    {SINGLE,     1,  VK_A ,      VK_M,  NULL},
    {SINGLE,    2,  VK_DOWN,   NULL,   NULL},
    {STOP,      1,   NULL,   NULL,   NULL}
};


/*Ex. Alt+M and key down twice*/
struct Key_Action Pos_Angelo[7] = {
    {SINGLE,    1,  VK_A,      NULL,  NULL},
    {SINGLE,    1,  VK_N,   NULL,   NULL},
     {SINGLE,    1,  VK_G,   NULL,   NULL},
      {SINGLE,    1,  VK_E,   NULL,   NULL},
       {SINGLE,    1,  VK_L,   NULL,   NULL},
    {SINGLE,      1,  VK_O,   NULL,   NULL},
      {STOP,      1,   NULL,   NULL,   NULL}
};


/*Ex. UNTESTED damage reparir removal
* open menu, scroll down 7 times, left arrow
*/
struct Key_Action Pos_DoNotRepair[4] = {
    {SINGLE,     1,  VK_LWIN,    VK_M,  NULL},
    {SINGLE,    13,  VK_DOWN,   NULL,   NULL},
    {SINGLE,    1,  VK_RETURN,   NULL,   NULL},
    {STOP,      1,   NULL,   NULL,   NULL}

};



struct Key_Action Pos_Strategy[3] = {
    {SINGLE,    1,  VK_STRATEGY_MENU,    NULL,  NULL},
    {SINGLE,    1,  VK_DOWN,   NULL,   NULL},
    {STOP,      1,   NULL,   NULL,   NULL}
};

struct Key_Action Pos_FuelAdd[3] = {
    {SINGLE,    1,  VK_STRATEGY_MENU,    NULL,  NULL},
    {SINGLE,    2,  VK_DOWN,   NULL,   NULL},
    {STOP,      1,   NULL,   NULL,   NULL}
};

struct Key_Action Pos_ChangeTyres[3] = {
    {SINGLE,    1,  VK_STRATEGY_MENU,    NULL,  NULL},
    {SINGLE,    3,  VK_DOWN,   NULL,   NULL},
    {STOP,      1,   NULL,   NULL,   NULL}
};
   
struct Key_Action Pos_ChangeBrakes[3] = {
    {SINGLE,    1,  VK_STRATEGY_MENU,    NULL,  NULL},
    {SINGLE,    11,  VK_DOWN,   NULL,   NULL},
    {STOP,      1,   NULL,   NULL,   NULL}
};

struct Key_Action Pos_ChangeDriver[3] = {
    {SINGLE,    1,  VK_STRATEGY_MENU,    NULL,  NULL},
    {SINGLE,    12,  VK_DOWN,   NULL,   NULL},
    {STOP,      1,   NULL,   NULL,   NULL}
};


struct Key_Action Pos_RepairSusp[3] = {
    {SINGLE,    1,  VK_STRATEGY_MENU,    NULL,  NULL},
    {SINGLE,    13,  VK_DOWN,   NULL,   NULL},
    {STOP,      1,   NULL,   NULL,   NULL}
};

struct Key_Action Pos_RepairBody[3] = {
    {SINGLE,    1,  VK_STRATEGY_MENU,    NULL,  NULL},
    {SINGLE,    14,  VK_DOWN,   NULL,   NULL},
    {STOP,      1,   NULL,   NULL,   NULL}
};
