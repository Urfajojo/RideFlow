**RideFlow** is a lightweight, modular, and open-source e-bike controller and telemetry platform for Linux, 
designed with customization, freedom, and extensibility in mind. Uses QML as the GUI. Currently built to be paired with a VESC.
proposed features are, BLE and GPS, but they will be implemented later.


### Prerequisites

- Qt 6.5+ (`qtdeclarative`, `qtquick`, `qtshapes`, etc.)
- C++ compiler with C++17 support
- Linux with SocketCAN enabled

### Build & Run

```bash
git clone https://github.com/urfajojo/RideFlow.git
cd RideFlow
mkdir build && cd build
cmake ..
make
./RideFlow
