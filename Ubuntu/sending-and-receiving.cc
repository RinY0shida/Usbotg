#include <iostream>
#include <fstream>
#include <string>

int main() {
    int flag;
    std::string moji;
    std::fstream serial("/dev/ttyACM1", std::ios::in | std::ios::out | std::ios::binary);
    if(serial.is_open()){
        std::cout << "Serial port is open" << std::endl;
    } else {
        std::cout << "Serial port is not open" << std::endl;
    }
    while(true){
        std::cin >> moji;
        serial << moji << std::endl;
         // std::cout << "moji: " << moji << std::endl;
        flag = true;
        while(flag){
            if(!std::getline(serial, moji)){
                std::cout << "stm32_receive:" << moji << std::endl;
                flag = false;
            }
        }
    }

     //sending data to the serial port
    // if (serial.is_open()) {
    //     serial << "Hello, World!" << std::endl;

    //      //reading data from the serial port
    //     std::string line;

    //     while (std::getline(serial, line)) {
    //         std::cout << line << std::endl;
    //     }

    // } 
    // else {
    //     std::cerr << "Error: Could not open serial port." << std::endl;
    // }


     //reading data from the serial port
     
    serial.close();
    return 0;
}