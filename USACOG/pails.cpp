#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int X, Y, M;
    cin >> X >> Y >> M;

    int MAX = 0;
    for (int i = 0; i <= M / X; ++i) {
        for (int j = 0; j <= M / Y; ++j) {
            int sum = X * i + Y * j;
            if (sum <= M) {
                MAX = max(MAX, sum);
            }
        }
    }

    cout << MAX << endl;
}