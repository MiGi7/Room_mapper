#include <vector>
#include "Point.h"


#ifndef PointMap_h
#define PointMap_h

    class PointMap {
        //Need to decide how the array is structured
        protected:
            std::vector<Point&> singleMap;
            Point offset;
            static int mapID;
            int map_size; 

        public:

            PointMap(int map_size);

            void addPointToMap(Point point);

            void printMap(int x);

            PointMap mergeMaps();
    };

#endif