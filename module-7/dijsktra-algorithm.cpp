#include <bits/stdc++.h>
using namespace std;
/*
    Steps
    1. Distance Array
    2. like BFS (1st takes a queue)
    3. path relexetion
*/
vector<pair<int, int>> adgh_list[105];
int dis[105];

void dijsktra(int src) {
    // queue<pair<int, int>> q ;

    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; 
    pq.push({0,src});
    dis[src]= 0;

    if(!pq.empty()){
        auto par= pq.top();
        pq.pop();
        int par_dist = par.first;
        int par_node = par.second;

        for(auto child: adgh_list[par_node]){
            int child_node = child.first;
            int child_dis = child.second;

            if(par_dist + child_dis < dis[child_node]){
                dis[child_node]= par_dist + child_dis;
                pq.push({dis[child_node], child_node});
            }

        }
    }

}

int main()
{
    int n, e;
    cin >> n >> e;
    
   while(e--){
    int a, b , c;
    cin >> a >> b >>c;
    adgh_list[a].push_back({b,c});
    adgh_list[b].push_back({a,c});
    
}

// memset(dis, INT_MAX, sizeof(dis));
    for(int i =0; i<n;i++)
    {
        dis[i]= INT_MAX;
    }
    dijsktra(0);
    for(int i =0; i<n; i++){
        cout << i << "-->" << dis[i] << endl ;
    }
   return 0;
}