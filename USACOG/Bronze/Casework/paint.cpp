#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("paint");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> bounds(4);

    for (int &a : bounds) {
        cin >> a;
    }

    //possible intersections are bounds[0] and bounds[2]
    if (bounds[1]<bounds[2] || bounds[3]<bounds[0]) {
        int painted=bounds[1]+bounds[3]-bounds[2]-bounds[0];
        cout << painted << endl;
        return 0;
    } else {
        int small=bounds[0];
        int big=bounds[0];
        for (int i=1; i<4; i++) {
            small=min(bounds[i], small);
            big=max(bounds[i], big);
        }

        cout << big-small << endl;
    }
}