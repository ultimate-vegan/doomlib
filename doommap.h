#ifndef DOOMMAP_H
#define DOOMMAP_H

#include "doomlib_global.h"
#include "thing.h"

enum linedefInfo{

    //offset in bytes within wad file
    offset,
    //starting vertex
    v_start,
    //ending vertex
    v_end,
    flags,
    types,
    tag,
    r_sidedef,
    //defaults to -1 if linedef does not adjoin 2 sectors
    l_sidedef = -1

};

enum linedefFlags{

    //blocks monsters and players
    IMPASS = 0X0001,
    //blocks only monsters
    IMPASS_MON = 0X0002,
    TWOSIDE = 0X0004,
    //upper unpegged
    UPPER_UP = 0X0008,
    //lower unpegged
    LOWER_UP = 0X0010,
    SECRET = 0X0020,
    BLKSND = 0X0040,
    NOMAP = 0X0080,
    ALWAYSMAP = 0X0100

};

/*
 * abbreviations:
 * LAC = lowest adjacent ceiling
 * HAL = highest adjacent level
 * CNO = close and open
 * HRAF = higher adjacent floor
 * HAF = highest adjacent floor
 * LAF = lowest adjacent floor
 */
enum linedefTypes{

    DR_DOOR = 1,
    W1_DOOR_STAYOPEN = 2,
    W1_DOOR_CLOSE = 3,
    W1_DOOR = 4,
    W1_FLR_TO_LAC = 5,
    W1_CRUSH_START_FAST = 6,
    S1_STAIRS_8 = 7,
    W1_STAIRS_8 = 8,
    S1_FLR_DONUT = 9,
    W1_LIFT_ALSOMON = 10,
    S1_EXIT = 11,
    W1_LGT_TO_HAL = 12,
    W1_LGT_255 = 13,
    S1_FLR_UP32_CHGTEX = 14,
    S1_FLR_UP24_CHGTEX = 15,
    W1_DOOR_CNO = 16,
    W1_LGT_BLINK1S = 17,
    S1_FLR_TO_HRAF = 18,
    W1_FLR_TO_HAF = 19,
    S1_FLR_TO_HRF_CHGTEX = 20,
    S1_LIFT = 21,
    W1_FLR_TO_HRF_CHGTEX = 22,
    S1_FLR_TO_LAF = 23

};

class DoomMap
{
public:
    DoomMap();
    uint32_t offset;
    std::string mapName;
    std::vector<Thing> thingList;
    std::vector<linedefInfo> lineList;
};

#endif // DOOMMAP_H
