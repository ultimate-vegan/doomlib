#include "wadfile.h"
#include "common.h"

WadFile::WadFile() {
    WadHeaders headers;
    vector<DirEntry> DirEntries;
    vector<DoomMap> levels;
}

void WadFile::getHeaders(){

    ifstream file(wadpath, ios::binary);

    //get iwad or pwad
    char wt[4];
    file.seekg(0);
    file.read(wt, 4);
    headers.wadtype = wt;

    //get number of lumps
    file.seekg(4);
    char cnl[4];
    file.read(cnl, 4);
    //translate to little endian encoding
    headers.numlumps =  static_cast<unsigned char>(cnl[0]) |
                       (static_cast<unsigned char>(cnl[1]) << 8) |
                       (static_cast<unsigned char>(cnl[2]) << 16) |
                       (static_cast<unsigned char>(cnl[3]) << 24);

    //get dir offset
    file.seekg(8);
    char cdo[4];
    file.read(cdo, 4);
    headers.diroffset = dc32(cdo[0],cdo[1],cdo[2],cdo[3]);


    //cout<<headers.wadtype<<'\n'<<headers.numlumps<<'\n'<<headers.diroffset<<'\n';

}

void WadFile::getDirEntries(){

    ifstream file(wadpath, ios::binary);
    int entrypos = headers.diroffset;

    for(auto it = 0; it < headers.numlumps; ++it){
        DirEntry entry;
        file.seekg(entrypos);

        char clo[4];
        char cls[4];
        char cln[8];

        //get lump offset
        file.read(clo, 4);
        entry.offset = dc32(clo[0],clo[1],clo[2],clo[3]);
        //get lump size
        file.seekg(entrypos+4);
        file.read(cls, 4);
        entry.size = dc32(cls[0],cls[1],cls[2],cls[3]);
        //get lump name
        file.seekg(entrypos+8);
        file.read(cln, 8);
        entry.name = cln;

        DirEntries.push_back(entry);

        entrypos = entrypos + 16;

        cout<<entry.name<<'\n'<<entry.offset<<'\n'<<entry.size<<'\n';
    }
}

void WadFile::getMaps(){

    ifstream file(wadpath, ios::binary);
    const regex pattern("E\\dM\\d");
    smatch match;

    for(auto it = DirEntries.begin(); it != DirEntries.end(); ++it){

        if(regex_match(it->name, match, pattern)){
            DoomMap map;
            map.offset = it->offset;
            levels.push_back(map);
        }
    }

}
