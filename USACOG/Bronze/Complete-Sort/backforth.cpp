#include <bits/stdc++.h>

using namespace std;

set<int> possible;

void barn_to_barn(int time, int a_tank, vector<int> a_buckets, int b_tank, vector<int> b_buckets) {
    if(time==4) {
        possible.insert(a_tank);
        return;
    }
    for(int i=0;i<a_buckets.size();i++) {
        vector<int> a_new=a_buckets;
        vector<int> b_new=b_buckets;
        int t=a_buckets[i];
        a_new.erase(begin(a_new)+i);
        b_new.push_back(t);

        barn_to_barn(time+1, b_tank+t, b_new, a_tank-t, a_new);
    }
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    vector<int> a(10);
    for (int &i : a) { cin >> i; }
    vector<int> b(10);
    for (int &i : b) { cin >> i; }

    barn_to_barn(0, 1000, a, 1000, b);
    cout << possible.size() << endl;
}