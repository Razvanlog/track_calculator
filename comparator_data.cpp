#include "comparator_data.h"
bool comparator_DATA::operator()(DATA a,DATA b){
        if (a.DISTANCE>b.DISTANCE)
        return 1;
        else if (a.DISTANCE==b.DISTANCE){
            if (a.CITY<b.CITY){
                return 1;
            }
            else return 0;
        }
        else return 0;
    }