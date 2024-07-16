#ifndef THINGS_H
#define THINGS_H

#include "doomlib_global.h"

struct ThingInfo{

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

class things
{
public:
    things();
};

#endif // THINGS_H
