//This is the Mac Daddy of this program. Uses QT
#include <iostream>
#include "conn_can/can.h"
#include "conn_can/mcu_can_frame.h"
using namespace std;
int main(){
    can::currentcan.can_open_socket("vcan0");
    can::currentcan.canreadtest(can::currentcan.canfd);
}
