#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n,p; //p is not used (is 0)
    cin >> n >> p;

    map<int, vector<int>> frequencies;
    for (int i = 0; i<n; i++) {
        int val;
        cin >> val;
        frequencies[val].push_back(i);
    }

    vector<vector<int>> ranges;
    for (const auto &[v, i] : frequencies) {
        ranges.push_back({i[0], i.back(), (int)i.size()});
    }
    sort(ranges.begin(), ranges.end());

    int diff=0;
    int start=ranges[0][0];
    int end=ranges[0][1];
    int most_common=0;
    for (const vector<int> &r : ranges) {
        if (r[0]>end) {
            diff += end-start+1-most_common;
            start=r[0];
            end=r[1];
            most_common=r[2];
        } else {
            end=max(end, r[1]);
            most_common=max(most_common, r[2]);
        }
    }
    diff += end-start+1-most_common;
    cout << diff << endl;
}