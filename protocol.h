#ifndef _PROT_
#define _PROT_

#include "keys.h"


#define VERSION     001

#define MAX_COMM    13

enum Command_Type {
    RAW,
    PRESET,
    OTHER
};

enum Preset_Actions {
    PR_TEST_a = 0x00,
    PR_LIMITER,
    PR_STRATEGY,
    PR_FUEL_ADD,
    PR_CHANGE_TYRES,
    PR_TYRE_SET,
    PR_TYRE_COMPOUND,
    PR_TYRE_ALL_PRESS,
    PR_TYRE_FL_PRESS,
    PR_BRAKES,
    PR_DRIVER,
    PR_SUSPENSION,
    PR_BODYWORK,
};

struct Protocol_Row {
    enum Command_Type   type;
    enum Preset_Actions  action;
    struct Key_Action   *key_act;
};









#endif