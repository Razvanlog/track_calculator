#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include "comparator_data.h"
using namespace std;
class dijkstra{
    private:
    int n_city,start_poz;
    int *min_dist_to_city,*viz;
    vector<vector<DATA>> connections;
    priority_queue<DATA,vector<DATA>,comparator_DATA> que;
    public:
    dijkstra();
    dijkstra(int N_CITY,int START_POZ,vector<vector<DATA>> CONNECTIONS);
    void execute();
    string answer(int poz);
};
#endif
