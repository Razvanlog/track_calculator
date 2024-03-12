#ifndef COMPARATOR_DATA_H
#define COMPARATOR_DATA_H
typedef struct data{
    int DISTANCE,CITY;
}DATA;
class comparator_DATA{
    public:
    bool operator()(DATA a,DATA b);
};
#endif