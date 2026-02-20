#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
int vis[1005]; // tracking visited array

// recursion 
void vfs (int src){
    vis[src] = true;
    cout << src << " ";
    for(int child: adj_list[src]){
        if(!vis[child])
        vfs(child);
    }
}

int main(){
    int n , e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    vfs(0);
    
    return 0;
}