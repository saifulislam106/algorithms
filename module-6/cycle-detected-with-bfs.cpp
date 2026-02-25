#include <bits/stdc++.h>
using namespace std;
vector<int> adgh_list[105];
bool vis[105];
int n, e;
int parent[105];
bool cycle;

void bfs(int src){
    vis[src]= true;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        // cout << par << endl;
        for(int child: adgh_list[par]){

            if(vis[child] && parent[par]!=child) // main logic 
            cycle = true;

            if(!vis[child])
            {
                q.push(child);
                vis[child]= true;
                parent[child]= par;

            }
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
            bfs(i);
    }
    if(cycle){
        cout << "Cycle Detected";
    }
    else cout << "No Cycle";
    return 0;
}