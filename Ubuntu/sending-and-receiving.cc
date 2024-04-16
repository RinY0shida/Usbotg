#include <iostream>
#include <fstream>
#include <string>

int main() {
    bool flag;
    std::string moji;
    std::fstream serial("/dev/ttyACM1", std::ios::in | std::ios::out | std::ios::binary);
    if(serial.is_open()){
        std::cout << "Serial port is open" << std::endl;
    } else {
        std::cout << "Serial port is not open" << std::endl;
        return 1;
    }
    while(true){
        std::cin >> moji;
        serial << moji << std::endl;
         // std::cout << "moji: " << moji << std::endl;
        flag = true;
        if(std::getline(serial, moji)){
            std::cout << "stm32_receive:" << moji << std::endl;
        }
    }
    serial.close();
    return 0;
}