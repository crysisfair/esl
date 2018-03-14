//
// Created by cristie on 18-3-14.
//

#include "top.h"

void top::sim() {
    pkt_dec_start = 0;
    sc_start(1.0, SC_NS);
    pkt_dec_start = 1;
    sc_start(1.0, SC_NS);
    pkt_dec_start = 0;
    sc_start(10.0, SC_NS);

    sc_stop();
    sc_close_vcd_trace_file(fp);
}
