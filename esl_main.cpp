//
// Created by cristie on 18-3-14.
//

#include <systemc.h>
#include "./comp/top.h"

int sc_main(int , char *[]) {
    top t("top");
    t.sim();
    return 0;
}