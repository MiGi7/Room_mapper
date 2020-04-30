#ifndef Point_h
#define Point_h

    class Point {
        public:
            float distance; //360 degree angle

            //the heading is the most important part
            //determines the overall image of the PointMap
            float angle;

            float x_from_origin;
            float y_from_origin;
            
        public:
            
            Point(float distance, float angle);

            void convertDistance();

            void calculateCoordinates(float angle, int quadrant);

            float* getCoordinates(float* array);

            void printCoordinates();

    };

#endif 
