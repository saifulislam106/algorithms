#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
pair<int,int> parent[1005][1005];

int n,m;

vector<pair<int,int>> d = {{0,1},{0,-1},{-1,0},{1,0}}; 

bool valid(int i,int j){
    return (i>=0 && j>=0 && i<n && j<m);
}

bool bfs(int si,int sj){

    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;

    while(!q.empty()){

        auto par = q.front();
        q.pop();

        int x = par.first;
        int y = par.second;

        if(grid[x][y] == 'D') return true;

        for(int i=0;i<4;i++){

            int nx = x + d[i].first;
            int ny = y + d[i].second;

            if(valid(nx,ny) && !vis[nx][ny] && (grid[nx][ny]=='.' || grid[nx][ny]=='D')){
                vis[nx][ny] = true;
                parent[nx][ny] = {x,y};
                q.push({nx,ny});
            }
        }
    }

    return false;
}

int main(){

    cin >> n >> m;

    int si,sj,di,dj;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];

            if(grid[i][j]=='R'){
                si=i;
                sj=j;
            }

            if(grid[i][j]=='D'){
                di=i;
                dj=j;
            }
        }
    }

    memset(vis,false,sizeof(vis));

    if(bfs(si,sj)){

        int x = di;
        int y = dj;

        while(!(x==si && y==sj)){

            auto p = parent[x][y];

            if(grid[p.first][p.second]=='.')
                grid[p.first][p.second] = 'X';

            x = p.first;
            y = p.second;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << grid[i][j];
        }
        cout << endl;
    }

}