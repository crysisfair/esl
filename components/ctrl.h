//
// Created by cristie on 18-3-10.
//

#ifndef ESL_CTRL_H
#define ESL_CTRL_H

#include <systemc.h>
#include "delay.h"

SC_MODULE(ctrl) {
    sc_in<bool> clk;
    sc_in<bool> pkt_cmd_vld;
    //sc_in<PktConfig> pkt_cmd_data;
    sc_in<bool> list_update_done;
    sc_out<bool> node_dec_start;

    sc_signal<bool> pkt_dec_start;
    sc_signal<int> pkt_cur_index;

    SC_CTOR(ctrl) {
        SC_METHOD(pkt_proc_func);
        sensitive << clk.pos();
        SC_METHOD(node_proc_func);
        sensitive << clk.pos();

        pkt_cmd_vld_1d = new delay<bool>("pkt_cmd_vld_reg", sc_time(1.0, SC_NS));

        pkt_cmd_vld_1d->in(pkt_cmd_vld);
        //pkt_cmd_vld_1d->en();
        pkt_cmd_vld_1d->out(pkt_dec_start);
    }

    delay<bool> *pkt_cmd_vld_1d;

    void pkt_proc_func();
    void node_proc_func();
};


#endif //ESL_CTRL_H
