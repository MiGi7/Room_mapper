#include <wiringSerial.h> 
#include <thread>
#include <mutex>
#include <iostream>

//char device[] = "/dev/ttyS0";
int serialRead = 1;
int serialWrite = 1;

int read(int fd){
    while(serialRead){
        std::cout << serialGetchar(fd) << std::endl;
    }
    return 0;
}

int write(){
    for(int i = 0; i < 1000; ++i){
        std::cout << "Writing: " << i << std::endl; 
    }
    return 0;
}

int main(){
    int fd = serialOpen(device, 115200);
    std::thread th1 (read, fd);
    std::thread th2 (write);
}



// int main(){
//     int fd = serialOpen(device, 115200);
//     //std::cout << fd <<  std::endl;
//     //int dataNum = serialDataAvail(fd);
//     //std::cout << dataNum << std::endl;
//     while (1){
// 	std::cout << serialGetchar(fd) << std::endl;
//     }

//     return 1;
// }
