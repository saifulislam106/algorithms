#include <bits/stdc++.h>
using namespace std;
vector<int> adgh_list[105];
bool vis[105];
int n, e;
int parent[105];
bool cycle;

void dfs(int src){
   vis[src]=true;

   for(int child: adgh_list[src]){
    if(vis[child] && parent[src]!= child){
        cycle= true;
    }
    if(!vis[child]){
        parent[child]= src;
        dfs(child);
    }
   }
    
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
        adgh_list[b].push_back(a);

    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
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