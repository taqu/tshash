#include "tshash.h"
#include <assert.h>
#include <stdlib.h>

int main(void)
{
    uint64_t seed = rand();
    uint64_t* hash = (uint64_t*)(malloc(sizeof(uint64_t)*1024));
    uint16_t* values = (uint16_t*)(malloc(sizeof(uint16_t)*1024));
    for(uint64_t i=0; i<1024; ++i){
        values[i] = (uint16_t)rand();
        hash[i] = tshash64(sizeof(uint16_t), &values[i], seed);
    }
    for(uint64_t i=0; i<1024; ++i){
        uint64_t x = tshash64(sizeof(uint16_t), &values[i], seed);
        assert(x == hash[i]);
    }
    free(values);
    free(hash);
    return 0;
}
