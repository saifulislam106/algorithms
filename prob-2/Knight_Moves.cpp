#include <bits/stdc++.h>
using namespace std;

int n,m;

vector<pair<int,int>> moves = {
    {-2,-1},{-2,1},
    {-1,-2},{-1,2},
    {1,-2},{1,2},
    {2,-1},{2,1}
};

bool valid(int x,int y){
    return (x>=0 && y>=0 && x<n && y<m);
}

int bfs(int sx,int sy,int dx,int dy){

    vector<vector<bool>> vis(n, vector<bool>(m,false));
    queue<pair<pair<int,int>,int>> q;

    q.push({{sx,sy},0});
    vis[sx][sy] = true;

    while(!q.empty()){

        auto par = q.front();
        q.pop();

        int x = par.first.first;
        int y = par.first.second;
        int dist = par.second;

        if(x==dx && y==dy) return dist;

        for(auto mv : moves){

            int nx = x + mv.first;
            int ny = y + mv.second;

            if(valid(nx,ny) && !vis[nx][ny]){
                vis[nx][ny] = true;
                q.push({{nx,ny},dist+1});
            }
        }
    }

    return -1;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        cin >> n >> m;

        int ki,kj;
        cin >> ki >> kj;

        int qi,qj;
        cin >> qi >> qj;

        cout << bfs(ki,kj,qi,qj) << endl;
    }

    return 0;
}