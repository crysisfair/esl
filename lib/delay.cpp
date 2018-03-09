#include "delay.h"//
// Created by cristie on 18-3-8.
//

//template<typename T>
//delay_transport<T>::delay_transport(sc_module_name name_, sc_time tdelay_) :
//        sc_module(name_),
//        tdelay(tdelay_),
//        in("in"), out("out")
//{
//    SC_METHOD(mi);
//    sensitive << in.value_changed();
//    SC_THREAD(mo);
//    sensitive << eq;
//}

//template<typename T>
//void delay_transport<T>::mi() {
//    val = in.read();
//    vq.push(val);
//    eq.notify(tdelay);
//}

//template<typename T>
//void delay_transport<T>::mo() {
//    while(1) {
//        wait();
//        val = vq.front();
//        out.write(val);
//        vq.pop();
//    }
//}
