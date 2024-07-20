#ifndef WADFILE_H
#define WADFILE_H

#include "doomlib_global.h"
#include "doommap.h"

using namespace std;

//wad file headers are 12 bytes long
struct WadHeaders{

    //IWAD or PWAD, first 4 bytes
    string wadtype;
    //number of lumps, second 4 bytes
    uint16_t numlumps;
    //offset to wad's directory, third 4 bytes
    uint32_t diroffset;

};

//directory entries are 16 bytes long
struct DirEntry{

    //offset to the start of the lump, first 4 bytes
    uint32_t offset;
    //size of the lump in bytes, second 4 bytes
    uint32_t size;
    //lump name, 8 byte ascii string
    string name;

};

class WadFile
{
public:
    WadFile();
    void getHeaders();
    void getDirEntries();
    void getMaps();

    WadHeaders headers;
    vector<DirEntry> DirEntries;
    vector<DoomMap> levels;

    string wadpath;
    ifstream file;
    //map data
    int num_maps;
};

#endif // WADFILE_H
