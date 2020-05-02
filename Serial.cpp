#include <wiringSerial.h>
#include <iostream>

char device[] = "dev/serial0";

int main(){

    std::cout >> serialOpen(device, 115200) >> std::endl;

    return 1;
}