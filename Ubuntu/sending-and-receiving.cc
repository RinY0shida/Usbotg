#include <iostream>
#include <fstream>

int main() {
    std::ofstream serial("/dev/ttyUSB0");
     //sending data to the serial port
    if(serialOut.is_open()) {
        serial << "Hello, World!" << std::endl;
    } else {
        std::cerr << "Error: Could not open serial port." << std::endl;
    }

     //reading data from the serial port
    std::ifstream serialIn("/dev/ttyUSB0");
    std::string line;

    while(std::getline(serialIn, line)) {
        std::cout << line << std::endl;
    }
    serialIn.close();
    return 0;
}