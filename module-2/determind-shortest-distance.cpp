// ----------------- Determind shortest distance -----------

#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005]; // array of vector
bool vst[1005]; // 1005 or etc size question a bola thakbe
int level[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vst[src]= true;
    level[src]= 0;

    // q theke ber kore ana
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        // oi node ke niye kaj kora
        // cout << par << " ";
        // child 
        for (int child: adj_list[par]){
            if(!vst[child]){
                q.push(child);
                vst[child]= true;
                level[child]= level[par]+1;
            }
        }
    }

}

int main(){
    int n, e;
    cin >> n>>e;
    while (e--)
    {
        int a, b;
        cin >>a >>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vst, false, sizeof(vst)); // visited array er value false kora
    memset(level, -1, sizeof(level));
    int src, dist;
    cin >> src >> dist;
    bfs(src);
    // for(int i =0; i<n;i++){
    //     cout << i << "-->" << level[i] << endl;
    // }
            cout  << level[dist] << endl;

     return 0;
}


// ----------------- Determind shortest distance path -----------

#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005]; // array of vector
bool vst[1005]; // 1005 or etc size question a bola thakbe
int level[1005];
int parant[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vst[src]= true;
    level[src]= 0;
    parant[src]= -1;

    // q theke ber kore ana
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        // oi node ke niye kaj kora
        // cout << par << " ";
        // child 
        for (int child: adj_list[par]){
            if(!vst[child]){
                q.push(child);
                vst[child]= true;
                level[child]= level[par]+1;
                parant[child]= par; 

            }
        }
    }

}

int main(){
    int n, e;
    cin >> n>>e;
    while (e--)
    {
        int a, b;
        cin >>a >>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vst, false, sizeof(vst)); // visited array er value false kora
    memset(level, -1, sizeof(level));
    memset(parant, -1, sizeof(parant));

    int src, dist;
    cin >> src >> dist;
    bfs(src);

    vector<int> path; // for path node reversing
    int node = dist;
    while (node != -1)
    {
        path.push_back(node);
        // cout  << node << " ";
        node = parant[node];
    }
    reverse(path.begin(), path.end());
    for(int x: path){
        cout << x << " ";
    }
    


     return 0;
}