#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
int n, m;

vector<pair<int,int>> d = {{-1,0},{1,0},{0,1},{0,-1}};

bool valid(int i,int j){
    if(i < 0 || j < 0 || i >= n || j >= m)
        return false;
    return true;
}

void bfs(int si,int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;

    while(!q.empty()){
        auto par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        for(int i=0;i<4;i++){
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]=='.'){
                vis[ci][cj] = true;
                q.push({ci,cj});
            }
        }
    }
}

int main(){

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    int si,sj;
    cin >> si >> sj;

    int di,dj;
    cin >> di >> dj;

    memset(vis,false,sizeof(vis));

    if(grid[si][sj]=='-' || grid[di][dj]=='-'){
        cout<<"NO";
        return 0;
    }

    bfs(si,sj);

    if(vis[di][dj]) cout<<"YES";
    else cout<<"NO";

    return 0;
}