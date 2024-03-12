#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "dijkstra.h"
#include "comparator_data.h"

using namespace std;
ifstream f("input_file.in");
ofstream g("output_file.out");
int N_CITY,NUMBER_OF_CONNECTIONS;
vector<vector <DATA>> CITY_CONNECTIONS(100001);
int main(){
    f>>N_CITY>>NUMBER_OF_CONNECTIONS;
    for (int i=0; i<NUMBER_OF_CONNECTIONS; i++){
        int X,Y,COST;
        f>>X>>Y>>COST;
        DATA TO_BE_INSERTED;
        TO_BE_INSERTED.CITY=Y;
        TO_BE_INSERTED.DISTANCE=COST;
        CITY_CONNECTIONS[X].push_back(TO_BE_INSERTED);
    }
    int X,Y;
    cin>>X>>Y;
    dijkstra program(N_CITY,X,CITY_CONNECTIONS);
    program.execute();
    for (int i=2; i<=N_CITY; i++){
            g<<i<<' '<<program.answer(i)<<'\n';
    }
    cout<<program.answer(Y)<<' ';
    return 0;
}