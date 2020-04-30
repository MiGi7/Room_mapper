#include "Point.h"
#include <iostream>

int main(){
    float array[2];
    Point a(2, 0);
    Point b(2, 90);
    Point c(2, 180);
    Point d(2, 270);
    a.printCoordinates();
    b.printCoordinates();
    c.printCoordinates();
    d.printCoordinates();
    std::cout << d.getCoordinates(array)[1] << std::endl;
    
    return 0;
}