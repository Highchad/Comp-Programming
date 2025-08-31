#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("citystate");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    vector<pair<string, string>> key;
    for (int i=0; i<n; i++) {
        string state, city;
        cin >> city >> state;
        string res=city.substr(0,2);
        key.push_back({res, state});
    }

    map<string, int> seen;
	long long total = 0;
	for (const auto &[c, s] : key) {
		if (c != s) { total += seen[s + c]; }
		seen[c + s]++;
	}
    cout << total << endl;
}