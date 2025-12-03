#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("outofplace");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int MAXN=3e5+13;
    
    int n;
    int swap=0;
    cin >> n;

    vector<int> heights(n);
    for (int &i : heights) {
        cin >> i;
    }
    vector<int> sorted=heights;
    sort(sorted.begin(), sorted.end());

    for (int i=0; i<n; i++) {
        if (sorted[i] != heights[i]) swap++;
    }

    cout << swap-1 << endl;
}