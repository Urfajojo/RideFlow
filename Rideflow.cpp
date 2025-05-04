//This is the Mac Daddy of this program. Uses QT
#include <iostream>
#include "opensocket.h"
#include "readcan.h"
#include <linux/can.h>
using namespace std;


int main(){
    openSocket("can0");
    if (isopen == true) {
        while (true) {
            ssize_t canval;
            canval = readcan(frame);
            if (canval != sizeof(can_frame)) {
                std::cerr << "Empty can frame" << std::endl;
            }
            }for (int i = 0; i < sizeof(can_frame); i++) {
                    cout << frame.data[i] << " ";
                }
            }
    throw runtime_error("Can server closed");
    return 0;
}
