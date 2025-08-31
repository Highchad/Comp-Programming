#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("cowqueue");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    vector<pair<int, int>> cows(n);
    for (int i=0; i<n; i++) { cin >> cows[i].first >> cows[i].second; }

    sort(cows.begin(), cows.end());

    int time=cows[0].first;
    for (int i=0; i<n-1; i++) {
        if (time+cows[i].second <= cows[i+1].first) {
            time=cows[i+1].first;
        } else if (time+cows[i].second > cows[i+1].first) {
            time+=cows[i].second;
        }
    }
    time+=cows[n-1].second;

    cout << time << endl;
}