#include "StringBuilder.h"




StringBuilder & StringBuilder::append(const std::string & str) {
    scratch.append(str);
    if (scratch.size() > ScratchSize) {
        main.append(scratch);
        scratch.resize(0);
    }
    return *this;
}

const std::string & StringBuilder::str() {
    if (scratch.size() > 0) {
        main.append(scratch);
        scratch.resize(0);
    }
    return main;
}