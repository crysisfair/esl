//
// Created by cristie on 18-3-10.
//

#include "ctrl.h"

void ctrl::pkt_proc_func() {
}

void ctrl::node_proc_func() {
    while(1) {
        wait();
        if(list_update_done) {
            node_dec_start.write(true);
            pkt_cur_index = pkt_cur_index + 1;
        }
    }
}
