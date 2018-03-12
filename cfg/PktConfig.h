//
// Created by cristie on 18-3-10.
//

#ifndef ESL_PKTCONFIG_H
#define ESL_PKTCONFIG_H

#include <vector>

#include "pattern.h"

class PktConfig {
public:
    int N;
    int K;
    std::vector<int> Bitmaps;
    std::vector<PatternType> Patterns;

    PktConfig();
    PktConfig(int N_, int K_);
};


#endif //ESL_PKTCONFIG_H
