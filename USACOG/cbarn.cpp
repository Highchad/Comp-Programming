#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> rooms(n);
    for(int i=0; i<n; i++) {
        cin >> rooms[i];
    }

    int big=(int)1e9;
    for(int j=0; j<n; j++) {
        int s=0;
        for(int a=0; a<n; a++) {
            s += rooms[(j+a)%n]*a;
        }
        big=min(big,s);
    }
    cout << big << "\n";

    return 0;
}