#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;

    vector<int> tuition(N);
    for (int &i : tuition) { cin >> i; }

    sort(tuition.begin(), tuition.end());

    int best_tuition=0;
    ll best_profit=0;
    ll current_profit=0;
    for (int i=0; i<N; i++) {
        current_profit=(long long)tuition[i]*(N-i);
        if (current_profit>best_profit) {
            best_profit=current_profit;
            best_tuition=tuition[i];
        }
    }
    cout << best_profit << " " << best_tuition << endl;
}