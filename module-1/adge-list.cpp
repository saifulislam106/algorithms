#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin >> n>>e;
    // vector<int> adj_list[n]; // array of vector
    vector<pair <int, int>> adge_list;
    while (e--)
    {
        int a, b;
        cin >>a >>b;
        adge_list.push_back({a,b});
        adge_list.push_back({b,a});
    }
  
        for( auto x : adge_list){ //pair<int, int> x
            cout << x.first << x.second << " ";
        }
        cout << endl;
     
}