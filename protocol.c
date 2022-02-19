

#include "protocol.h"


struct Protocol_Row Table[MAX_COMM] = {
    {PRESET,    PR_TEST_a,          &Pos_Angelo },
    {PRESET,    PR_LIMITER,         &Pos_DoNotRepair },
    {PRESET,    PR_STRATEGY,        &Pos_Strategy},
    {PRESET,    PR_FUEL_ADD,        &Pos_FuelAdd},
    {PRESET,    PR_CHANGE_TYRES,    &Pos_ChangeTyres},
    {PRESET,    PR_TYRE_SET,        &Pos_ChangeTyres},
    {PRESET,    PR_TYRE_COMPOUND,   &Pos_ChangeTyres},
    {PRESET,    PR_TYRE_ALL_PRESS,  &Pos_ChangeTyres},
    {PRESET,    PR_TYRE_FL_PRESS,   &Pos_ChangeTyres},
    {PRESET,    PR_BRAKES,          &Pos_ChangeBrakes},
    {PRESET,    PR_DRIVER,          &Pos_ChangeDriver},
    {PRESET,    PR_SUSPENSION,      &Pos_RepairSusp},
    {PRESET,    PR_BODYWORK,        &Pos_RepairBody}


};
