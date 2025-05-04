//This is the Mac Daddy of this program. Uses QT
#include <iostream>
#include "opensocket.h"
using namespace std;
int main(){
    openSocket("can0");
    while (isopen) {
    readcan();
    }
    return 0;

}
