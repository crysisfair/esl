//
// Created by cristie on 18-3-10.
//

#include "ctrl.h"

void ctrl::pkt_proc_func() {
}

void ctrl::node_proc_func() {
    if(list_update_done == 1 || pkt_dec_start == 1) {
        node_dec_start = 1;
        pkt_cur_index = pkt_cur_index + 1;
    }
    else {
        node_dec_start = 0;
    }
}
