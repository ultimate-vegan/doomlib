#ifndef THING_H
#define THING_H

#include "doomlib_global.h"

enum ThingTypes{

    //invisible types
    P1ST = 1,
    P2ST = 2,
    P3ST = 3,
    P4ST = 4,
    DMST = 11,
    TPLN = 14,
    SPST = 87,
    MONS = 89,

    //monsters
    SPID = 7,
    SPOS = 8,
    CYBR = 16,
    SPEC = 58,
    VILE = 64,
    CPOS = 65,
    SKEL = 66,
    FATT = 67,
    BSPI = 68,
    BOS2 = 69,
    PAIN = 71,
    KEEN = 72,
    SSWV = 84,
    TROO = 3001,
    SARG = 3002,
    BOSS = 3003,
    POSS = 3004,
    HEAD = 3005,
    SKUL = 3006,
    BAR1 = 2035,

    //weapons
    SGN2 = 82,
    SHOT = 2001,
    MGUN = 2002,
    LAUN = 2003,
    PLAS = 2004,
    CSAW = 2005,
    BFUG = 2006,

    //ammo
    CELP = 17,
    CLIP = 2007,
    SHEL = 2008,
    ROCK = 2010,
    BROK = 2046,
    CELL = 2047,
    AMMO = 2048,
    SBOX = 2049,

    //powerups
    MEGA = 83,
    SOUL = 2013,
    BON1 = 2014,
    BON2 = 2015,
    PINV = 2022,
    PSTR = 2023,
    PINS = 2024,
    PMAP = 2026,
    PVIS = 2045,
    BPAK = 8,
    STIM = 2011,
    MEDI = 2012,
    ARM1 = 2018,
    ARM2 = 2019,
    SUIT = 2025,

    //keys
    BKEY = 5,
    YKEY = 6,
    RKEY = 13,
    RSKU = 38,
    YSKU = 39,
    BSKU = 40,

    //obstacles
    POL1 = 25,
    POL6 = 26,
    POL4 = 27,
    POL2 = 28,
    POL3 = 29,
    COL1 = 30,
    COL2 = 31,
    COL3 = 32,
    COL4 = 33,
    CBRA = 35,
    COL5 = 36,
    COL6 = 37,
    CEYE = 41,
    FSKU = 42,
    TRE1 = 43,
    TBLU = 44,
    TGRN = 45,
    TRED = 46,
    SMIT = 47,
    ELEC = 48,
    GOR1 = 49,
    GOR2 = 50,
    GOR3 = 51,
    GOR4 = 52,
    GOR5 = 53,
    TRE2 = 54,
    SMBT = 55,
    SMGT = 56,
    SMRT = 57,
    FCAN = 70,
    HDB1 = 73,
    HDB2 = 74,
    HDB3 = 75,
    HDB4 = 76,
    HDB5 = 77,
    HDB6 = 78,
    TLMP = 85,
    TLP2 = 86,
    COLU = 2028,

    //decorations
    BLD1 = 10,
    BLD2 = 12,
    PDED = 15,
    ZDED = 18,
    SDED = 19,
    IDED = 20,
    DDED = 21,
    CDED = 22,
    KDED = 23,
    POL5 = 24,
    CAND = 34,
    GOR2D = 59,
    GOR4D = 60,
    GOR3D = 61,
    GOR5D = 62,
    GOR1D = 63,
    POB1 = 79,
    POB2 = 80,
    BRS1 = 81

};

enum ThingFlags{

    EASY = 0x001,
    MED = 0X002,
    HARD = 0X004,
    DEAF = 0X008,
    MPONLY = 0X0010

};

class Thing
{
public:
    Thing();

    uint32_t offset;

    //x position of a thing
    int16_t xpos;
    //y position of a thing
    int16_t ypos;
    //angle of a thing
    int16_t angle;
    //type of thing
    int16_t type;
    //thing options
    int16_t flags;
};

#endif // THINGS_H
