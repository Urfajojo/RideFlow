//This is the Mac Daddy of this program. Uses QT
#include <iostream>
#include "conn_can/can.h"
#include "conn_can/mcu_can_frame.h"
using namespace std;
mcu_can_frame t1;
int main(){
    can::currentcan.can_open_socket("vcan0");
    can::currentcan.cansendtest(can::currentcan.canfd);
}
