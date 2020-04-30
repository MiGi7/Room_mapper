#include "Point.h"
#include <iostream>
#include <math.h>  

Point::Point(float distance, float angle): distance{distance}, angle{angle} {
    this->convertDistance();
}

void Point::convertDistance(){
    if (angle < 90) {
        this->calculateCoordinates(angle, 1); 
    } else if (angle < 180) {
        this->calculateCoordinates(angle - 90, 2);
    } else if (angle < 270) {
        this->calculateCoordinates(angle - 180, 3);
    } else {
        this->calculateCoordinates(angle - 270, 4);
    }
}

void Point::calculateCoordinates(float angle, int quadrant){
    float sinAngle = sin(angle);
    float cosAngle = cos(angle);
    switch (quadrant) {
        case 1:
            x_from_origin = sinAngle * distance;
            y_from_origin = cosAngle * distance;
            break;
        case 2:
            x_from_origin = cosAngle * distance;
            y_from_origin = sinAngle * distance * -1;
            break;
        case 3: 
            x_from_origin = sinAngle * distance * -1;
            y_from_origin = cosAngle * distance * -1;
            break;
        case 4:
            x_from_origin = cosAngle * distance * -1;
            y_from_origin = sinAngle * distance;
            break;
    }   
}

float* Point::getCoordinates(float* array){
    array[0] = x_from_origin;
    array[1] = y_from_origin;
    return array;
}

void Point::printCoordinates(){
    std::cout << "X: " << x_from_origin << std::endl;
    std::cout << "Y: " << y_from_origin << std::endl;
}