#ifndef _KEYS_
#define _KEYS_

#include <windows.h>


enum key_type {
    COMBO,
    SINGLE,
    INHERIT_SEQUENCE
    NONE
};

struct Key_Action {
    enum key_type type,
    uint8_t         repeat;
    uint8_t         key1;
    uint8_t         key1;
    void  (*linked_seq)(void);
};

extern struct Key_Action Pos_second_row[];


#endif
