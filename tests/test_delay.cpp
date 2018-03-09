//
// Created by cristie on 18-3-9.
//
#include <systemc>
#include "delay.h"

void test_delay() {
    sc_clock clk("clk", 1.0, SC_NS);
    sc_signal<bool> in;
    sc_signal<bool> out;
    sc_signal<bool> en;
    delay<bool> d("d1", sc_time(2.0, SC_NS));
    d.in(in);
    d.out(out);
    d.en(en);
    sc_trace_file *fp = sc_create_vcd_trace_file("tr_delay");
    fp->set_time_unit(1.0, SC_PS);
    sc_trace(fp, in, "in");
    sc_trace(fp, en, "en");
    sc_trace(fp, out, "out");

    en.write(0);
    in.write(0);
    sc_start(1, SC_NS);
    in.write(1);
    sc_start(2, SC_NS);
    in.write(0);
    sc_start(1, SC_NS);
    in.write(0);
    sc_start(3, SC_NS);

    en.write(1);
    in.write(0);
    sc_start(1, SC_NS);
    in.write(1);
    sc_start(2, SC_NS);
    in.write(0);
    sc_start(1, SC_NS);
    in.write(0);
    sc_start(3, SC_NS);

    sc_stop();
    sc_close_vcd_trace_file(fp);
}

int sc_main (int, char *[]) {
    test_delay();
    return 0;
}

