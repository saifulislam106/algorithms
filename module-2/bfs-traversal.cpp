
// -------------- node can visited or not ---------
#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005]; // array of vector
bool vst[1005]; // 1005 or etc size question a bola thakbe

void bfs(int src){
    queue<int> q;
    q.push(src);
    vst[src]= true;

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
    int src, dist;
    cin >> src >> dist;
    bfs(src);
    if(vst[dist])
        cout << "YES";
    else
                cout << "NO";
    
     return 0;
}

