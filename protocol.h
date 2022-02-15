#ifndef _PROT_
#define _PROT_

#include keys.h

enum Command_Type {
    RAW,
    PRESET,
    OTHER
};

enum Preset_Actions {
    PR_OPEN_MENU,
    PR_FUEL,
    PR_PRESSURE_FR,
    PR_PRESSURE_FL,
    PR_DAMAGE
};

struct Protocol_Row {
    enum Command_Type   type;
    enum Preset_Action  action;
    struct Key_Action   *key_act;
};







#endif