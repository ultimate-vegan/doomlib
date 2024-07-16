#include "common.h"


//convenience function so i dont have to type this all the time
uint32_t dc32(char d1, char d2, char d3, char d4){
    return static_cast<uint32_t>(static_cast<unsigned char>(d1))|
           static_cast<uint32_t>(static_cast<unsigned char>(d2))<<8|
           static_cast<uint32_t>(static_cast<unsigned char>(d3))<<16|
           static_cast<uint32_t>(static_cast<unsigned char>(d4))<<24;
}
