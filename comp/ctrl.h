//
// Created by cristie on 18-3-10.
//

#ifndef ESL_CTRL_H
#define ESL_CTRL_H

#include <systemc.h>
#include "../utils/delay.h"

SC_MODULE(ctrl) {
    sc_in<bool> clk;
    sc_in<bool> pkt_dec_start;
    //sc_in<PktConfig> pkt_cmd_data;
    sc_in<bool> list_update_done;
    sc_out<bool> node_dec_start;

    sc_out<int> pkt_cur_index;


    void pkt_proc_func();
    void node_proc_func();

    SC_CTOR(ctrl) {
        SC_METHOD(pkt_proc_func);
        sensitive << clk.pos();
        SC_METHOD(node_proc_func);
        sensitive << clk.pos();
    }
};


#endif //ESL_CTRL_H
