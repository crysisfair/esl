//
// Created by cristie on 18-3-8.
//

#ifndef SIMPLE_FIFO_DELAY_H
#define SIMPLE_FIFO_DELAY_H
#include <systemc.h>
#include <queue>

template<typename T>
class delay: public sc_module {

public:
    sc_in<T> in;
    //sc_in<bool> en;
    sc_out<T> out;
    sc_time tdelay;

    SC_HAS_PROCESS(delay);
    //delay_transport(sc_module_name name_, sc_time tdelay_);
    delay(sc_module_name name_, sc_time tdelay_) :
            sc_module(name_),
            tdelay(tdelay_),
            in("in"), out("out")
    {
        SC_METHOD(mi);
        sensitive << in.value_changed();
        SC_THREAD(mo);
        sensitive << eq;
    }

protected:
    sc_event_queue eq;
    std::queue<T> vq;
    T latch;
    T val;
    //void mi();
    //void mo();
    void mi() {
        //if(en.read()) {
            latch = in.read();
        //}
        vq.push(latch);
        eq.notify(tdelay);
    }

    void mo() {
        while(1) {
            wait();
            val = vq.front();
            out.write(val);
            vq.pop();
        }
    }

};
#endif //SIMPLE_FIFO_DELAY_H
