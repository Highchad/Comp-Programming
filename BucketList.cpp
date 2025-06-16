#include <bits/stdc++.h>
using namespace std;

const int TIME=1000;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> buckets(TIME, 0);
    for(int i=0; i<N; i++) {
        int s, t, b;
        cin >> s >> t >> b;
        for(int j=s; j<t; j++) { buckets[j]+=b; }
    }

    int needed=0;
    for(int i=0; i<TIME; i++) { needed = max(needed, buckets[i]); }
    cout << needed << endl;
}
