#include <fstream>
#include <iostream>
#include <string>

int main(const int, const char* const[]) {
    std::ifstream infile("/nfs/site/disks/fm_vt_0073/work/dmedin2/home/dmv_home/code/SimpleCode/log.txr");
    if (!infile.is_open()) std::perror("Couldn't open file");

    for (std::string line; std::getline(infile, line);) {
        std::cout << line << std::ends;
    }

    return 0;
}
