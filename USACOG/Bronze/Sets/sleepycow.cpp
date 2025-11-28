#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("herding");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> positions(3);
    for (int &a : positions) {
        cin >> a;
    }
    sort(positions.begin(), positions.end());

    if (positions[0]==positions[2]-2) {
        cout << 0 << endl;
    } else if ((positions[1]-positions[0]==2) || (positions[2]-positions[1]==2)) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

    cout << max((positions[2]-positions[1]), (positions[1]-positions[0]))-1 << endl;
}