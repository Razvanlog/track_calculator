#include "dijkstra.h"
using namespace std;
dijkstra::dijkstra(){
        n_city=0;
        start_poz=0;
}
dijkstra::dijkstra(int N_CITY,int START_POZ,std::vector<std::vector<DATA>> CONNECTIONS){
        n_city=N_CITY;
        start_poz=START_POZ;
        connections=CONNECTIONS;
        min_dist_to_city=(int*)malloc(sizeof(int)*(n_city+2));
        memset(min_dist_to_city,0,(n_city+2)*sizeof(*min_dist_to_city));
        return;
}
void dijkstra::execute(){
        DATA*new_data=(DATA*)malloc(sizeof(DATA));
        new_data->CITY=start_poz;
        new_data->DISTANCE=0;
        que.push(*new_data);
        while (!que.empty()){
            DATA front=que.top();
            que.pop();
            int cur_city=front.CITY,cur_dist_trav=front.DISTANCE;
            for (int j=0; j<connections[cur_city].size(); j++){
                int next_city=connections[cur_city][j].CITY,new_total_dist=cur_dist_trav+connections[cur_city][j].DISTANCE;
                if (min_dist_to_city[next_city]>new_total_dist || min_dist_to_city[next_city]==0){
                    min_dist_to_city[next_city]=new_total_dist;
                    DATA *new_data=(DATA*)malloc(sizeof(DATA));
                    new_data->CITY=next_city;
                    new_data->DISTANCE=new_total_dist;
                    que.push(*new_data);
                    free(new_data);
                }
            }
        }
    min_dist_to_city[start_poz]=0;
}
string dijkstra::answer(int poz){
        if (min_dist_to_city[poz]==0){
            return "not accesible";
        }
        else{
            string a="";
            int temp=min_dist_to_city[poz];
            while (temp){
                a=a+(char)(temp%10+'0');
                temp=temp/10;
            }
            string b="";
            for (int it=a.size()-1; it>=0; it--){
                b+=a[it];
            }
            return b;
        }
    }