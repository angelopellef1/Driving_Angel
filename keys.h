#ifndef _KEYS_
#define _KEYS_


typedef unsigned char uint8_t;

enum key_type {
    COMBO,
    SINGLE,
    INHERIT_SEQUENCE,
    NONE,
    STOP
};

struct Key_Action {
    enum key_type beha;
    uint8_t         repeat;
    uint8_t         key1;
    uint8_t         key2;
    void  (*linked_seq)(void);
};

extern struct Key_Action Pos_second_row[];
extern struct Key_Action Pos_DoNotRepair[];
extern struct Key_Action Pos_Angelo[];
extern struct Key_Action Pos_Strategy[];
extern  struct Key_Action Pos_FuelAdd[];
extern  struct Key_Action Pos_ChangeTyres[];
extern  struct Key_Action Pos_ChangeBrakes[];
extern  struct Key_Action Pos_ChangeDriver[];
extern  struct Key_Action Pos_RepairSusp[];
extern  struct Key_Action Pos_RepairBody[];









//#define VK_ALT 0x12
//#define VK_LEFT 0x25
//((#define VK_DOWN 0x28


enum Letter_Key {
    VK_A = 0x41,
    VK_B,
    VK_C,
    VK_D,
    VK_E,
    VK_F,
    VK_G,
    VK_H,
    VK_I,
    VK_J,
    VK_K,
    VK_L,
    VK_M,
    VK_N,
    VK_O,
    VK_P,
    VK_Q,
    VK_R,
    VK_S,
    VK_T,
    VK_U,
    VK_V,
    VK_W,
    VK_X,
    VK_Y,
    VK_Z
};


#define VK_STRATEGY_MENU    0x39
#define VK_HUD_CYCLE        0x30

#endif
