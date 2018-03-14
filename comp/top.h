//
// Created by cristie on 18-3-14.
//

#ifndef ESL_TOP_H
#define ESL_TOP_H

#include <systemc.h>
#include "ctrl.h"
#include "dec_proc.h"

SC_MODULE(top) {
    sc_signal<bool> list_update_done;
    sc_signal<bool> pkt_dec_start;
    sc_signal<bool> node_dec_start;
    sc_signal<int> cur_index;
    dec_proc *p;
    ctrl *c;
    sc_trace_file *fp;

    SC_CTOR(top) {
        sc_clock clk("clk", 1.0, SC_NS);
        p->clk(clk);
        p->node_dec_start(node_dec_start);
        p->list_update_done(list_update_done);
        c->clk(clk);
        c->pkt_dec_start(pkt_dec_start);
        c->pkt_cur_index(cur_index);
        c->node_dec_start(node_dec_start);
        c->list_update_done(list_update_done);
        fp = sc_create_vcd_trace_file("tr_top");
        fp->set_time_unit(1.0, SC_PS);
        sc_trace(fp, clk, "clk");
        sc_trace(fp, pkt_dec_start, "pkt_dec_start");
        sc_trace(fp, node_dec_start, "node_dec_start");
        sc_trace(fp, cur_index, "cur_index");
    }

    void sim();
};


#endif //ESL_TOP_H
