#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    vector<string> data(N);
    for (int i=0; i<N; i++) {
        cin >> data[i];
    }

    vector<vector<int>> beat(N, vector<int>(N, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (data[i][j] != 'D') {
                if (data[i][j] == 'W') {
                    beat[i][j] = 1;
                } else {
                    beat[j][i] = 1;
                }
            }
        }
    }

    for (int i=0; i<M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        int winning=0;
        for (int k=0; k<N; k++) {
            if (beat[k][x] && beat[k][y]) {
                winning++;
            }
        }

        int total=N*N;
        int losing=(N-winning)*(N-winning);

        cout << total-losing << endl;
    }
    return 0;
}