#include <bits/stdc++.h>
using namespace std;

int main(){
   long long int n , q;
    cin >> n >> q;

    vector<long long int> pre(n+1, 0);

    for(int i=1; i<=n; i++){
        int val = (i -1)/3 +1;
        pre[i]= pre[i-1]+ val;
    }

    while (q--)
    {
       long long int l, r;
        cin >> l >>r;

        long long int sum = pre[r]- pre[l-1];
        cout << sum << endl;

    }
    
    return 0;
}