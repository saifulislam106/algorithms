#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        int left = 0, right = n - 1;

        int maxHeight = -1;
        int ansL = 0, ansR = 0;

        while (left < right) {
            int height = min(h[left], h[right]);

            if (height > maxHeight) {
                maxHeight = height;
                ansL = left;
                ansR = right;
            }

            if (h[left] < h[right]) {
                left++;
            } else {
                right--;
            }
        }

        cout << ansL << " " << ansR << endl;
    }

    return 0;
}