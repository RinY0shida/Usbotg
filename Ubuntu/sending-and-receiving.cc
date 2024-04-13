#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::fstream serial("/dev/ttyUSB0", std::ios::in | std::ios::out | std::ios::binary);

     //sending data to the serial port
    if (serial.is_open()) {
        serial << "Hello, World!" << std::endl;

         //reading data from the serial port
        std::string line;

        while (std::getline(serial, line)) {
            std::cout << line << std::endl;
        }

    } 
    else {
        std::cerr << "Error: Could not open serial port." << std::endl;
    }

     //reading data from the serial port
     
    serial.close();
    return 0;
}