#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int MAXN=3e5+13;
    
    int N, K;
    cin >> N >> K;

    vector<ll> days(N);
    for (ll &d: days) cin >> d;

    ll last_day=days[0];
    ll cost=K+1;
    for (ll d : days) {
        if (d-last_day<K+1) {
            cost += d-last_day;
        } else {
            cost += K+1;
        }
        last_day = d;
    }
    cout << cost << endl;
}