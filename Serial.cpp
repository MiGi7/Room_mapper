#include <wiringSerial.h> 
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

std::mutex m;

char device[] = "/dev/ttyS0";
int serialRead = 1;
int serialWrite = 1;
char c;

int read(int fd){
    while(serialRead){
        m.lock();
        c = serialGetchar(fd);
        m.unlock();
        std::cout << c << std::endl;
    }
    return 0;
}

int write(int fd){
    while(serialWrite){
        serialPutchar(c);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    return 0;
}

int main(){
    int fd = serialOpen(device, 115200);
    std::thread th1 (read, fd);
    std::thread th2 (write, fd);

    th1.join();
    th2.join();
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
