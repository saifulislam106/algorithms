#include <bits/stdc++.h>
using namespace std;
vector<int> adgh_list[105];
bool vis[105];
bool pathVis[105]; // path visite for directed cycle detected
int n, e;
bool cycle;

void dfs(int src){
   vis[src]=true;
   pathVis[src]= true;

   for(int child: adgh_list[src]){
    if(vis[child] && pathVis[child]){
        cycle= true;
    }
    if(!vis[child]){
        dfs(child);
    }
   }
   pathVis[src]= false;
}

int main()
{
    cin >> n >>e;
    cycle = false; 
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adgh_list[a].push_back(b);
    }

    memset(vis, false, sizeof(vis));
    memset(pathVis, false, sizeof(pathVis));
    for(int i =0; i<n; i++){
        if(!vis[i])
            dfs(i);
    }
    if(cycle){
        cout << "Cycle Detected";
    }
    else cout << "No Cycle";
    return 0;
}