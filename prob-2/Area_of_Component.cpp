#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int n,m;

vector<pair<int,int>> d = {{-1,0},{1,0},{0,1},{0,-1}};

bool valid(int i,int j){
    return (i>=0 && j>=0 && i<n && j<m);
}

int bfs(int si,int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;

    int area = 1;

    while(!q.empty()){
        auto par = q.front();
        q.pop();

        int x = par.first;
        int y = par.second;

        for(int i=0;i<4;i++){
            int nx = x + d[i].first;
            int ny = y + d[i].second;

            if(valid(nx,ny) && !vis[nx][ny] && grid[nx][ny]=='.'){
                vis[nx][ny] = true;
                q.push({nx,ny});
                area++;
            }
        }
    }

    return area;
}

int main(){

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    memset(vis,false,sizeof(vis));

    int mn = INT_MAX;
    bool found = false;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && !vis[i][j]){
                int area = bfs(i,j);
                mn = min(mn, area);
                found = true;
            }
        }
    }

    if(!found) cout << -1;
    else cout << mn;

    return 0;
}