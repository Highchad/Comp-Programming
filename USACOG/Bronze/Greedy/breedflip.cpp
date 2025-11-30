#include <bits/stdc++.h>
using namespace std;

void flip(string &s, int l, int r) {
    for (int i = l; i <= r; i++) {
        if (s[i] == 'H') s[i] = 'G';
        else s[i] = 'H';
    }
}

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int N;
    cin >> N;
    string a, b;
    cin >> a >> b;

    int ans = 0;
    int lower = 0, upper = N - 1;

    while (a != b) {
        // find earliest mismatch
        while (lower <= upper && a[lower] == b[lower]) lower++;
        // find latest mismatch
        while (upper >= lower && a[upper] == b[upper]) upper--;

        if (lower > upper) break;

        flip(b, lower, upper);
        ans++;
    }

    cout << ans << "\n";
}
