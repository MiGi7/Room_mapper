#include <wiringSerial.h> 
#include <iostream>

char device[] = "/dev/ttyS0";

int main(){
    int fd = serialOpen(device, 115200);
    //std::cout << fd <<  std::endl;
    //int dataNum = serialDataAvail(fd);
    //std::cout << dataNum << std::endl;
    while (1){
	std::cout << serialGetchar(fd) << std::endl;
    }

    return 1;
}
