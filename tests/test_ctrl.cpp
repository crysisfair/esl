//
// Created by cristie on 18-3-12.
//

#include <systemc.h>
#include "PktConfig.h"
#include "ctrl.h"

int sc_main(int, char *[]) {
    sc_clock clk("clk", 1.0, SC_NS);
    sc_signal<bool> list_update_done;
    sc_signal<bool> pkt_cmd_vld;
    sc_signal<bool> pkt_cmd_data;
    sc_signal<bool> node_dec_start;

    ctrl c("ctrl");
    sc_trace_file *fp = sc_create_vcd_trace_file("tr_ctrl");
    fp->set_time_unit(1.0, SC_PS);
    sc_trace(fp, list_update_done, "list_update_done");
    sc_trace(fp, clk, "clk");
    sc_trace(fp, node_dec_start, "dec_start");
    sc_trace(fp, pkt_cmd_vld, "pkt_cmd_vld");
    c.clk(clk);
    c.pkt_cmd_vld(pkt_cmd_vld);
    c.list_update_done(list_update_done);
    c.node_dec_start(node_dec_start);

    pkt_cmd_vld.write(0);
    list_update_done.write(0);
    sc_start(1, SC_NS);
    list_update_done.write(1);
    sc_start(1, SC_NS);
    list_update_done.write(0);
    sc_start(2, SC_NS);
    list_update_done.write(1);
    sc_start(1, SC_NS);
    list_update_done.write(0);
    sc_start(2, SC_NS);

    sc_stop();
    sc_close_vcd_trace_file(fp);
}