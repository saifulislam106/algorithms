#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
int vis[1005]; // tracking visited array

// recursion 
void dfs (int src){
    vis[src] = true;
    // cout << src << " ";
    for(int child: adj_list[src]){
        if(!vis[child])
        dfs(child);
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
    int sum;
    for(int i =0 ;i<n; i++){
        if(vis[i]== false){

            dfs(i);
            sum ++;
        }
    }
    cout <<sum << endl;

    
    return 0;
}