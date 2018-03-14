//
// Created by cristie on 18-3-14.
//

#ifndef ESL_DEC_PROC_H
#define ESL_DEC_PROC_H

#include <systemc.h>

SC_MODULE(dec_proc) {
    sc_in<bool> node_dec_start;
    sc_in<bool> clk;
    sc_out<bool> list_update_done;

    void dec_proc_func();

    SC_CTOR(dec_proc) {
        SC_METHOD(dec_proc_func);
        sensitive << clk.pos();
    }
};


#endif //ESL_DEC_PROC_H
