#include "doomlib.h"
#include "wadfile.h"

WadFile test;

void shit(){
    test.wadpath = "/home/vegan/games/games_ssd/wads/doom/.played/origwad/ORIGWAD.PWD";
    test.getHeaders();
    test.getDirEntries();
    test.getMaps();
}

int main(){
    shit();
}
