#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> v(n);
    for(int i =0; i<n; i++){
        cin >> v[i];
    }

    vector <long long int> pre(n, 0);
    pre[0]= v[0];
    for(int i =1; i<n; i++){
        pre[i]= pre[i-1] +v[i];
    }

    long long sum  = pre[n-1];

    for(int i =0; i<n; i++){
        long long lSum = pre[i];
        long long rSum = sum -pre[i] + v[i];
        if(lSum == rSum){
            cout << lSum << " " << i+1 << endl;
            return 0;
        }
    }
    cout << "UNSTABLE\n";
    return 0;
}