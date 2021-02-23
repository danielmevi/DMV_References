#include <cstdint>

using namespace std;

struct ret {
    int corr;
};

// logic function tht returns result
ret mylogic(int* val, uint8_t* val2, ret obj, int f){

    // for loop from 0 to 10000
    for(unsigned i = 0; i < 10000; i++){
        if (i < 500)
        val[i] = *(val2 + i) * 5;
        else 
        val[i] = *(val2 + i) * 10;
    }
    // for loop from 0 to 10000
    for(size_t i = 0; i < 10000; i++){
        int val3 = 0;
        if (f) val3 = 30;
        else val3 = 20;

        if (i > 500 && i < 800)
        val[i] = *(val2 + i) + val3;
        else 
        val[i] = *(val2 + i) + val3;
    }
    // for loop from 0 to 10000
    for(long i = 0; i < 10000; i++){
        int val4 = 0;
        if (f) val4 = 100;
        else val4 = 200;
        val[i] = val[i] + val4;
    }

    if (val[0]) {
        obj.corr = 1;
        return obj; 
    }
    else {
        obj.corr = 0;
        return obj; 
    }

}

int main() {

}